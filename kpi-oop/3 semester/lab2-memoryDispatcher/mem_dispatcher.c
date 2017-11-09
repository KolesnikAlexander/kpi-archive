/******************************************
*file: test.c
*synopsis: memory dispatcher functions
*related files: none
*author: Kolesnik
*written: 02/12/2016
*last modified: 02/12/2016
*******************************************/
#include "mem_dispatcher.h"
char *statusToString(STATUS st) {
	return st == FREE ? "free" : "allocated";
}
void show_memory_map(mem_dispatcher *md) {
	mem_chunk *p = md->first;
	printf("Memory map\n-------------\n");
	while (p)
	{
		printf("block id: %d	size: %d	status: %s\n",p->id,p->size,statusToString(p->status));
		p = p->next;
	}
}
mem_chunk* chunkConstructor(int id,int size,STATUS status,struct tag_mem_chunk* next ){
	mem_chunk *node;
	node = (mem_chunk*)malloc(sizeof(mem_chunk));
	node->id = id;
	node->size = size;
	node->status = status;
	node->next = next;
	return node;
}
void init(mem_dispatcher *md) {

	md -> first = (mem_chunk*)malloc(sizeof(mem_chunk));
	md->last_id_used = 0;

	md->first->id = 0;
	md->first->size = HEAP_SIZE;
	md->first->status = FREE;
	md->first->next = NULL;

}
int allocate(mem_dispatcher *md, int size) {
	if (size < 0)
		return -1;
	if (size == 0)
		return 0;

	mem_chunk *p = md->first;
	mem_chunk *smallestSizeChunk = NULL;

	//serching the smallest memory block
	while (p != NULL) {
		if ((p->status == FREE)&&(p->size >= size))
		{
			smallestSizeChunk = p;
			p = p->next;
			break;
		}
		p = p->next;
	}
	if (smallestSizeChunk == NULL)
		return -1;
	while (p != NULL) {
		if ((p->status == FREE)&&(p->size < smallestSizeChunk->size))
			smallestSizeChunk = p;
		p = p->next;
	}

	//creating a new node
	if (smallestSizeChunk->size == size)
		{
			smallestSizeChunk->status = ALLOCATED;
			return smallestSizeChunk->id;
		}
	else
		{
			md->last_id_used++;
			mem_chunk* newChunk = chunkConstructor(md->last_id_used, size, ALLOCATED, smallestSizeChunk->next);
			smallestSizeChunk->size = smallestSizeChunk->size - size;
			smallestSizeChunk->next = newChunk;
			return newChunk->id;
		}
}
int deallocate(mem_dispatcher *md, int block_id) {
	
	if((block_id <= -1)||(md->last_id_used < block_id))
		return -1;
	mem_chunk *p = md->first;
	while (p != NULL) {
		if (p->id == block_id)
		{
			p->status = FREE;
			break;
		}
		p = p->next;
	}
	return 0;

}
void reuniteTwoBlocks(mem_chunk *first, mem_chunk *second) {
	mem_chunk *beforeSecond = first;

	while (beforeSecond->next != second)
		beforeSecond = beforeSecond->next;

	beforeSecond->next = second->next;
	first->size = (first->size) + (second->size);
	free(second);
}
void defragment(mem_dispatcher *md) {
	mem_chunk *p = md->first;
	mem_chunk *firstFree = NULL;
	while (p != NULL) {
		if (p->status == FREE)
		{
			firstFree = p;
			p = p->next;
			break;
		}
		p = p->next;
	}
	if (firstFree == NULL)
		return;
		
	else
	{
		mem_chunk *secondFree = p;
		while (secondFree != NULL)
		{
			while (secondFree != NULL) {
				if (secondFree->status == FREE)
				{
					break;
				}
				secondFree = secondFree->next;
			}

			if (secondFree == NULL)
				return;

			reuniteTwoBlocks(firstFree, secondFree);
			secondFree = firstFree->next;
		}
		
	}

}