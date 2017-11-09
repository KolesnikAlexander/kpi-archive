#include <stdio.h>
#include <windows.h>
#include <iostream>
using namespace std;
double ususal() {

	char b;
	int c;
	int a1;
	int A[7];
	a1 = 3;
	c = 0;
	for (b = 0; b < 7; b++) {
		c += 3;
		if (c < 9)
			a1 = 5 * c + b + 1;
		else
			a1 = b << 2;
		A[b] = a1;
	}
	for (b = 0; b < 7; b++)
		printf("%d ", A[b]);
	printf("\n");
	return 0;
}

int asmblr() {

	char b;
	int c;
	int a1;
	int A[7];
	a1 = 3;
	c = 0;
	_asm {
		// 9    : 	for (b = 0; b < 7; b++) {
			 mov b, 0
			 jmp SHORT $LN4
			 $LN2:
		     mov al, b
			 add al, 1
			 mov	 b, al
			 $LN4:
			 movsx eax, b
			 cmp	 eax, 7
			 jge	 SHORT $LN3
			 // 10   : 		c += 3;
			 mov	 eax, c
			 add	 eax, 3
			 mov	c, eax
			 // 11   : 		if (c < 9)
			 cmp c , 9
			 jge SHORT $LN8
			 // 12   : 			a1 = 5 * c + b + 1;
			 imul	eax,c,5
		     movsx ecx, b
			 lea edx, DWORD PTR[eax + ecx + 1]
			 mov a1,edx
			 // 13   : 		else
			 jmp SHORT $LN9
			 $LN8:
			 // 14   : 			a1 = b << 2;
		     movsx eax,b
			 shl eax, 2
			 mov a1,eax
			 $LN9:
			 // 15   : 		A[b] = a1;
			 movsx	 eax, b
			 mov	 ecx, a1
			 mov	 A[eax*4], ecx

				// 16   :

	jmp	 SHORT $LN2
			$LN3:
	}
	for (b = 0; b < 7; b++)
		printf("%d ", A[b]);
	printf("\n");
	return 0;
	}
int asmblrMod() {

	char b;
	int c;
	int a1;
	int A[7];
	a1 = 3;
	c = 0;
	_asm {
		// 9    : 	for (b = 0; b < 7; b++) {

			 mov	 b, 0
			 jmp	 SHORT $LN4
			 $LN2:
		     //mov al, b
			 //add al, 1
			 // mov	 b, al
			 inc b
			 $LN4:
			 movsx eax, b
			 cmp	 eax, 7
			 jge	 SHORT $LN3
			 // 10   : 		c += 3;
			 mov	 eax, c
			 add	 eax, 3
			 mov	c, eax
			 // 11   : 		if (c < 9)
			 cmp c , 9
			 jge SHORT $LN8
			 // 12   : 			a1 = 5 * c + b + 1;
			 imul	eax,c,5
		     movsx ecx, b
			 lea edx, DWORD PTR[eax + ecx + 1]
			 mov a1,edx
			 // 13   : 		else
			 jmp SHORT $LN9
			 $LN8:
			 // 14   : 			a1 = b << 2;
		     movsx eax,b 
			 shl eax, 2
			 mov a1,eax	
			 $LN9:
			 // 15   : 		A[b] = a1;
			 movsx	 eax, b
			 mov	 ecx, a1
			 mov	 A[eax*4], ecx

				// 16   :

	jmp	 SHORT $LN2
			$LN3:
	}
	for (b = 0; b < 7; b++)
		printf("%d ", A[b]);
	printf("\n");
	return 0;
	}

/*4*/ int main() {
	printf("C++\n");
	ususal();
	printf("Assembler\n");
	asmblr();
	printf("Improverd assembler\n");
	asmblrMod();
	system("pause");
	/*17*/ return 0;
	/*18*/}


