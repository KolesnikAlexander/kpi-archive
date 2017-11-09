#include "argz.h"
int main() {
	char *argz;
	size_t argz_len;

	// argz_create_sep() test
	error_t result = argz_create_sep("SHELL = / bin / bash:usr =monty  : = / bin / monty : LANG = en_US.UTF - 8", 58 /*ASCII for : */, &argz, &argz_len);
	printf("_____________\n");
	printf("argz_create_sep():\n");
	printf("Vector argz:\n");
	argz_print(argz, argz_len);
	printf("_____________\n");
	//argz_count() test
	printf("argz_count():\n");
	printf("Number of elements: ");
	printf("%zu",argz_count(argz, argz_len));
	printf("\n_____________\n");
	//argz_add() test
	result = argz_add(&argz, &argz_len, "Hello world");
	printf("argz_add():\n");
	printf("Vector argz:\n");
	argz_print(argz, argz_len);
	printf("\n_____________\n");
	//argz_delete() test
	char *test_pointer = argz+21;//pointer to the second element
	argz_delete(&argz, &argz_len, test_pointer);
	printf("argz_delete():\n");
	printf("Vector argz:\n");
	argz_print(argz, argz_len);
	printf("\n_____________\n");
	//argz_insert test
	argz_insert(&argz, &argz_len, test_pointer, "Hi");
	printf("argz_insert():\n");
	printf("Vector argz:\n");
	argz_print(argz, argz_len);
	printf("\n_____________\n");
	//argz_next test
	printf("argz_next:\n");
	for (char *entry = argz; entry; entry = argz_next(argz, argz_len, entry))
		printf("%s\n", entry);
	printf("\n_____________\n");
//argz_replace() test
	printf("argz_replace:\n");
	argz_replace(&argz, &argz_len, argz, "Changed string");
	argz_print(argz, argz_len);
	printf("\n_____________\n");
	getchar();
	return 0;
}