#pragma once
/*!
* file: StringList.h
* StringList class declaration
* written: 01/06/2012
* Copyright (c) 2012 by Yu.Zorin
*/

#include <stdio.h>

class cString {
public:
	char* string;
	//constructors/destructor
	cString();
	cString(const char *psz);
	cString(const cString& stringSrc);


	~cString();

	//methods
	int GetLength() const;
	bool IsEmpty()const;
	void Empty();
	void SetAt(int nIndex, char ch);
	int Compare(const cString &s) const;
	int Find(char ch) const;
	int Find(char *pszSub) const;

	cString Mid(int nFirst, int nCount) const;
	cString Left(int nCount) const;
	cString Right(int nCount) const;

	//operators
	//cString& operator =(const cString& stringSrc);
	//const cString& operator =(const unsigned char* psz);
	//char operator [](int indx);
	//cString& operator =(const cString& stringSrc);

	//cString operator +(const cString& string);
	//cString& operator +=(const cString& string);
	//
	void Print();
private:
	
};
