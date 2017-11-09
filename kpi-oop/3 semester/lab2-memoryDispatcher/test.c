/******************************************
*file: test.c
*synopsis: memory dispatcher test
*related files: none
*author: Kolesnik
*written: 02/12/2016
*last modified: 02/12/2016
*******************************************/

#include "mem_dispatcher.h"
int main() {

	mem_dispatcher *memory = (mem_dispatcher*)malloc(sizeof(mem_dispatcher));
	init(memory);
	while (1) {
		int key;
		printf("-------------\n");
		printf("MENU\n");
		printf("1.Allocate\n");
		printf("2.Deallocate\n");
		printf("3.Show memory map\n");
		printf("4.Defragment\n");
		printf("5.Exit\n");
		printf("-------------\n");
		scanf("%d", &key);
		printf("\n");
		switch (key)
		{
		case 1:
		{
			printf("Enter block size:");
			scanf("%d", &key);

			if (allocate(memory, key) == -1)
				printf("Allocation failed\n");
			else
				printf("Allocation is successful\n");
		}break;
		case 2:
		{
			printf("Enter block id:");
			scanf("%d", &key);

			if (deallocate(memory, key) == -1)
				printf("Deallocation failed\n");
			else
				printf("Dellocation is successful\n");
		}break;
		case 3:
		{
			show_memory_map(memory);
		}break;
		case 4:
		{
			defragment(memory);
			printf("Defragmentation is successful\n");
		}break;
		case 5:
		{
			return 0;
		}break;
		default:printf("Wrong input\n");
		
		}
	}

}