#pragma once
#include "Node.h"

template<class T>
class BinTree {
public:
	BinTree() :root(NULL) {};
	void addItem(T *itm);
	void print();
	void printAndDel(bool(*cond)(Node<T>* checkElem, T* measElem ), T* measElem); //check elem - current elem, measElem - element with condition
	void delItem(T* item);
	Node<T>* root;
private:

};

template<class T>
Node<T>* addRecursive(Node<T>* newItem, Node<T>* currentItem) {
	if (newItem == NULL) {
		return currentItem;
	}
	if (currentItem == NULL) {
		return newItem;
	}


	if (*(newItem->value) <= *(currentItem->value)) {
		currentItem->left = addRecursive(newItem, currentItem->left);
	}
	else
	{
		currentItem->right = addRecursive(newItem, currentItem->right);
	}

	return currentItem;
}
template<class T>
void BinTree<T>::addItem(T* itm) {
	root = addRecursive(new Node<T>(itm, NULL, NULL, NULL), root);
}

template<class T>
void printRecursive(Node<T>* node, int level) {
	if (node == NULL) return;
	else
	{
		node->print(level);
		printRecursive(node->left, level + 1);
		printRecursive(node->right, level + 1);
	}
	return;
}
template<class T>
void BinTree<T>::print() {
	printRecursive(root, 0);
}


template<class T>
Node<T>* delRecursive(Node<T>* curNode, T* delItem) { //prevBranch: 0 -left, 1 - right
	if (curNode == NULL)
		return NULL;

	curNode->left = delRecursive(curNode->left, delItem);
	curNode->right = delRecursive(curNode->right, delItem);
	if (*(curNode->value) == *delItem)
	{
		Node<T>* leftLink = curNode->left;
		Node<T>* rightLink = curNode->right;

		cout << endl << "Deleted item:" << endl;
		curNode->print(-1);
		delete curNode;
		leftLink = addRecursive(rightLink, leftLink);
		return leftLink;
	}
	return curNode;
}
template<class T>
void BinTree<T>::delItem(T* item) {
	root = delRecursive(root, item);

}

template<class T>
Node<T>* delCondRecursive(Node<T>* curNode, bool(*cond)(Node<T>* checkElem, T* measElem), T* measElem) { //prevBrancg: 0 -left, 1 - right
	if (curNode == NULL)
		return NULL;

	curNode->left = delCondRecursive(curNode->left, cond, measElem);
	curNode->right = delCondRecursive(curNode->right, cond, measElem);
		if(cond(curNode, measElem))
	{
		Node<T>* leftLink = curNode->left;
		Node<T>* rightLink = curNode->right;

		curNode->print(-1);
		delete curNode;
		leftLink = addRecursive(rightLink, leftLink);
		return leftLink;
	}
	return curNode;
} 


template<class T>
void BinTree<T>::printAndDel(bool(*cond)(Node<T>* checkElem, T* measElem), T* measElem) {
	root = delCondRecursive(root, cond, measElem);
}