#include "mystring.h"
#include<stdio.h>
int main() {
	//substr() check 
	printf("Test of 'SUBSTR'\n");
	printf("________________\n");
	char str1[] = { "asfsdxhfsdhxh" };
	char str2[] = { "dxh" };
	printf("String 1:'%s'\n",str1);
	printf("String 2:'%s'\n", str2);
	int a = substr(str1, str2);
	if (a == -1) printf("Is not a substring\n");
	else printf("Substring begins from %d\n", a);
	//end of substr() check 

	//subseq() check 
	printf("\nTest of 'SUBSEQ'\n");
	printf("________________\n");
	char str3[] = { "123456789" };
	char str4[] = { "123dg12345" };
	printf("String 1:'%s'\n", str3);
	printf("String 2:'%s'\n", str4);
	printf("Maximum length of the common subsequence: %d\n",subseq(str3, str4));
	//end of subseq() check 
	//ispol() check 
	printf("Test of 'ISPOL'\n");
	printf("________________\n");
	char str5[] = { "123321" };
	printf("String:'%s'\n", str5);
	if (ispol(str5)) printf("String '%s' is a palindrom\n",str5);
	else printf("String '%s' is not a palindrom\n", str5);
	//end of ispol() check 

	//makepal() check 
	printf("\nTest of 'MAKEPAL'\n");
	printf("________________\n");
	char* str6 = (char*)malloc(13);
	strcpy(str6,"1232");
	printf("String: %s\n", str6);
	char* pal6 = makepal(str6);
	printf("Palindrom string: %s\n", pal6);
	//end of makepal() check 
	

	//text2double check 
	printf("\nTest of 'TEXT2DOUBLE'\n");
	printf("________________\n");
	char *str7 = "6.15;8.79;61.395654;34.67;78.321;6;7.356;8.256;8;890";
	int a1 = 0;
	int *a1p = &a1;
	printf("String:'%s'\n", str7);
	double *array7 = txt2double(str7, a1p);
	if (array7 != NULL)
	{
		printf("ARRAY:\n");
		int i;
		for (i = 0; i < a1; i++) {
			printf("%f\n", array7[i]);
		}
	}
	else
		printf("Wrong input");
	//text2double check 
	getchar();
	return 0;

	
}