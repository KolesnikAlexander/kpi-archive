#pragma once
#include <iomanip> 

#define FORMAT_ENABLED true
#define NODE_FORMAT_WITH 10


template<class T>
class Node {
public:
	T* value;
	Node* prev;
	Node* left;
	Node* right;
	Node(T* data, Node<T>* prev, Node<T>* left, Node<T>* right);
	~Node();
	void print(int level);
};


template<class T>
Node<T>::Node(T* data, Node<T>* prev, Node<T>* left, Node<T>* right) {
	this->value = data;
	this->prev = prev;
	this->left = left;
	this->right = right;
}

template<class T>
void Node<T>::print(int level) {
	if (FORMAT_ENABLED)
		cout << "\tLevel: " << level << endl;
	if (value == NULL)
		cout << "NULL" << endl;
	else
		cout << *value << endl;
}

template<class T>
 Node<T>::~Node() {
	delete prev;
	delete value;

}