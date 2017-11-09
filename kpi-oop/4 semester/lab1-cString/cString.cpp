#include <iostream>
using namespace std;
#include "cString.h"
#include <string.h>

cString::cString() {
	this->string = new char('\0');
}
cString::cString(const char *psz) {
	this->string = new char[strlen(psz) + 1];
	strcpy_s(this->string, strlen(psz)+1, psz);
}
cString::~cString() {
	delete this->string;
	printf("\n destructor workls for string!!\n");
}
cString::cString(const cString& stringSrc){
	this->string = new char[strlen(stringSrc.string) + 1];
	strcpy_s(this->string, strlen(stringSrc.string) + 1, stringSrc.string);

}
int cString:: GetLength() const{
	return strlen(this->string);
}
bool cString::IsEmpty()const {
	return (strlen(this->string) == 0);
}