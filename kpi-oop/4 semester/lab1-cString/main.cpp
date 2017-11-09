#include <iostream>
using namespace std;
#include "cString.h"


int main() {

	{
/*
		cString a;  //Object a is stored in the stack
		cString* b;//b is a pointer to  cString
			b = new cString;
					//a is deleted automatically after the execution leaves the scope of a
			delete b;//b is deleted

*/
		cString str1;
		printf("1)%s\n", str1.string);
		printf("	1-Length:%d\n", str1.GetLength());
		printf("	1-IsEmpty:%d\n", str1.IsEmpty());

		cString str2("String 2");
		printf("2)%s\n", str2.string);
		printf("	2-IsEmpty:%d\n", str2.IsEmpty());

		const cString* str3 = new cString("String 3");
		printf("3)%s\n", str3->string);

		cString* str4 = new cString("Some string 4");
		printf("4)%s\n", str4->string);
		printf("	4-Length:%d\n", str4->GetLength());
		//const cString& aliasStr4 = str4;
		cString str5(*str4);
		printf("5)%s\n",str5.string);

		cString str6(str2);
		printf("6)%s\n", str6.string);
		printf("	6-Length:%d\n", str6.GetLength());

		delete str3;
		delete str4;
		
	}
	
	}