/************************************************************************
*file: argz.c
*synopsis: The argz functions use malloc/realloc to allocate/grow argz vectors, and so any argz
* vector creating using these functions may be freed by using free; conversely, any argz
* function that may grow a string expects that string to have been allocated using malloc
* (those argz functions that only examine their arguments or modify them in place will work
* on any sort of memory). All argz functions that do memory allocation have a return type
* of error_t, and return 0 for success, and ENOMEM if an allocation error occurs.
* These functions are declared in the include file "argz.h".
*related files: none
*author: Kolesnik
*written: 14/11/2016
*last modified: 16/11/2016
************************************************************************/

#include "argz.h"
/*
The argz_create_sep function converts the null-terminated string string into an
argz vector (returned in argz and argz len) by splitting it into elements at every
occurrence of the character sep.
*/

error_t argz_create_sep(const char *string, int sep, char **argz, size_t *argz_len) {
	if (sep < 0 || sep > 255)
		return ERR;

	*argz_len = strlen(string) + 1;

	if (*argz_len == 1)
		return ERR;

	if ((*argz = (char*)malloc((*argz_len) * sizeof(char))) == NULL)
		return ERR;

	for (size_t i = 0; i < *argz_len; i++)
	{
		if (*(string + i) == sep)
		{
			*(*argz + i) = '\0';
		}
		else
		{
			*(*argz + i) = *(string + i);
		}
	}
	return OK;
}
/*prints argz vector */
void argz_print(const char *argz, size_t arg_len) {
	for (size_t i = 0; i < arg_len; i++)
	{
		if (*(argz + i) != '\0')
			printf("%c", *(argz + i));
		else
			printf("\n");
	}
}
//Returns the number of elements in the argz vector.
size_t argz_count(const char *argz, size_t arg_len) {
	size_t result = 0;
	for (size_t i = 0; i < arg_len; i++)
	{
		if (*(argz + i) == '\0')
			result++;
	}

	return result;

}
//The argz_add function adds the string str to the end of the argz vector // *argz, and updates *argz and *argz_len accordingly.
error_t argz_add(char **argz, size_t *argz_len, const char *str) {
	char *exp_vect; //expanded vector
	size_t exp_vect_length = *argz_len + strlen(str);//expanded vector length
	//if ((*argz = (char*)malloc((*argz_len) * sizeof(char))) == NULL)
	if ((exp_vect = (char*)realloc(*argz, exp_vect_length * sizeof(char))) == NULL)
		return ERR;
	else
	{
		for (size_t i = 0; i < strlen(str); i++) {
			*(exp_vect + *argz_len + i) = *(str + i);
		}
		*argz = exp_vect;
		*argz_len = exp_vect_length;
		return OK;
	}
}
/*If entry points to the beginning of one of the elements in the argz vector *argz,
the argz_delete function will remove this entry and reallocate *argz,
modifying *argz and *argz_len accordingly. Note that as destructive argz 
functions usually reallocate their argz argument, pointers into argz vectors 
such as entry will then become invalid.
*/

	void argz_delete(char **argz, size_t *argz_len, char *entry) {
		char *part_to_del = entry;
		while (*part_to_del != '\0')
			part_to_del++;
		int k = part_to_del - entry;
		memmove(entry, part_to_del + 1, (*argz_len - (part_to_del+1 - *argz)));
		*argz_len = *argz_len - (part_to_del-entry+1);
		*argz = realloc(*argz, *argz_len * sizeof(char));
}
	/*
	The argz_insert function inserts the string entry into the argz vector *argz 
	at a point just before the existing element pointed to by before, reallocating 
	*argz and updating *argz and *argz_len. If before is 0, entry is added to the
	end instead (as if by argz_add). Since the first element is in fact the same 
	as *argz, passing in *argz as the value of before will result in entry being 
	inserted at the beginning.
	*/

	error_t argz_insert(char **argz, size_t *argz_len, char *before, const char *entry) {
		size_t entry_len = strlen(entry);
		*argz_len = *argz_len + entry_len;
		*argz = realloc(*argz, *argz_len * sizeof(char));
		if (before < *argz)
			return ENOMEM;
		memmove(before + entry_len, before, *argz_len - (before - *argz));
		memmove(before, entry, entry_len);
		return OK;
	}
	/*
	The argz_next function provides a convenient way of iterating over the elements in the argz vector argz. It returns a pointer to the next element in argz after the element entry, or 0 if there are no elements following entry. If entry is 0, the first element of argz is returned.
	This behavior suggests two styles of iteration:
	char *entry = 0;
	while ((entry = argz_next (argz, argz_len, entry)))
	action;
	(the double parentheses are necessary to make some C compilers shut up about what they consider a questionable while-test) and:
	char *entry;
	for (entry = argz; entry; entry = argz_next (argz, argz_len, entry))
	action;
	Note that the latter depends on argz having a value of 0 if it is empty (rather than a pointer to an empty block of memory); this invariant is maintained for argz vectors created by the functions here.
	*/

char *argz_next (char *argz, size_t argz_len, const char *entry){
	if (entry == NULL)
		return argz;
	for (char* ptr = entry; ptr < argz + argz_len; ptr++){
		if (ptr == argz + argz_len -1)
			return 0;
		else if (*ptr == '\0'){
			return ptr+1;
		}
	}
	return 0;
}
/*
Replace the string str in argz with string with, reallocating argz as
necessary.
*/

error_t argz_replace(char **argz, size_t *argz_len, const char *str, const char *with) {
	{
		const int len1 = strlen(str);
		const int len2 = strlen(with);

		if (len1 == 0 || len2 == 0)
			return ENOMEM;

		char *ptr = *argz, *begin = NULL;

		while (ptr < *argz + *argz_len)
		{
			begin = strstr(ptr, str);

			if (begin == NULL)
			{
				ptr += strlen(ptr) + 1;
				continue;
			}
			else break;
		}

		if (begin == NULL)
			return ENOMEM;

		if (len1 < len2)
		{
			if (realloc(*argz, (*argz_len - len1 + len2) * sizeof(char)) == NULL)
				return ENOMEM;

			memmove(begin + len2, begin + len1, *argz_len - (begin - *argz + len1) * sizeof(char));
		}
		else if (len1 > len2)
		{
			memmove(begin + len2, begin + len1, *argz_len - (begin - *argz + len1) * sizeof(char));

			if (realloc(*argz, (*argz_len - len1 + len2) * sizeof(char)) == NULL)
				return ENOMEM;
		}

		for (int i = 0; i < len2; i++)
		{
			*(begin + i) = *(with + i);
		}

		*argz_len += len2 - len1;

		return OK;
	}

}
