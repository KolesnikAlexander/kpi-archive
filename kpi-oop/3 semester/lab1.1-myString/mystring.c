#include "mystring.h" 
char *substrRec(const char *string1, const char *string2) {
	if ((*string1 == '\0') || (*string2 == '\0')) return NULL;
	const char *p1 = string1;
	const char *p2 = string2;
	while (*p1 == *p2) {
		if (*p1 == '\0') break;
		p1++;
		p2++;
	}
	if ((*p1 != '\0') && (*p2 == '\0')) return string1; //Main string didn't terminated, second one did -> 2 str is a substring
	if ((*p1 == '\0') && (*p2 != '\0')) return NULL;//Main string terminated, second one didn't -> Substring was not found
	if ((*p1 == '\0') && (*p2 == '\0')) return string1;//Both strings terminated -> They are the same
	else substrRec(string1 + 1, string2);//Characters differ -> Start checking from the next character
}
//returns the index of the element in 'string1' that's the beginning of substring 'string2'
int substr(const char *string1, const char *string2) {
	char *res = substrRec(string1, string2);
	if (NULL != res) return res - string1;
	else return -1;
}

//returns the maximum length of the common subsequence of 'string1' and 'string2'
int subseq(const char *string1, const char *string2) {
	int str1Len = strlen(string1);
	int str2Len = strlen(string2);
	const char *strMask;//string that is searched
	const char *mainStr;//string in which strMask is searched
	int maxSubseq = 0;
	if (str1Len <= str2Len) //sting1 is the shortest string
	{
		strMask = string1;
		mainStr = string2;
	}
	else
	{
		strMask = string2;
		mainStr = string1;
	}
	char *strMaskEnd = strMask + strlen(strMask);//points to term zero
	while (strMaskEnd >= strMask)
	{
		char sevedElement = *strMaskEnd;
		*strMaskEnd = '\0';
		strMaskEnd--;
		char *p = strMaskEnd;
		while (p >= strMask)
		{
			int subsLen = strlen(p);
			if ((substr(mainStr, p) != -1) && (subsLen > maxSubseq))
			{
				maxSubseq = subsLen;
			}
			p--;
		}
		strMaskEnd++;
		*strMaskEnd = sevedElement;
		strMaskEnd--;

	}
	return maxSubseq;

}

//Empty string is considered a palindrom
//Returns 1 if the string is a palindrom and 0 in other case
char ispol(const char *string) {
	//return ispolBool(string) ? 1:0;
	char *head = string;
	char *tail = string + (strlen(string) - 1);
	while (head < tail)
	{
		if (*head != *tail)
			break;
		head++;
		tail--;
	}
	if (head >= tail) return 1;
	else return 0;
}

//subPol points to the end of the part of 'string' that should be added to make a palindrom
//Adds string terminated with subPol to 'string'
//Returns a string that is a palindrom
char* addToTailPol(const char *string, const char *subPol) {
	int extraSize = subPol - string;
	int offset = subPol - string;
	char *newString = (char*)realloc(string,strlen(string) + offset+1);
	char *newSubPol = newString + offset;
	char *p2 = newSubPol;
	while (*p2 != '\0') p2++;//move pointer to term zero
	char *p1 = newSubPol-1;
	while (p1 >= newString)
	{
		*p2 = *p1;
		p1--;
		p2++;
	}
	*p2 = '\0'; 
	return newString;
}
//Adds minimum of symbols to the end of the string to make a palindrom
char* makepal(const char *string) {
	char *p = string;
	while (!ispol(p))
	{
		p++;
	}
	return addToTailPol(string, p);

}
//Returns NULL if any parameter is NULL or to < from
//Returns string between pointers 'from' and 'to'
char *mkStrFromTo(char* from, char* to) {
	char *res = NULL;
	if ((NULL == from) || 
		(NULL == to) ||
		(to < from)) 
		res = NULL;
	else if ((from == to) && (*from == '\0')) {
		*res = '\0';
	}
	else {
		int subStrLen = to - from + 2;
		res = malloc(subStrLen);
		int i;
		for (i = 0; i <= (to - from); i++)
			res[i] = from[i];
		
		res[i] = '\0';
	}
	
	return res;
}
//returns double if 'str' can be turned to double
//or 0 in other case
double processWord(char *str) {
	double convToDouble = atof(str);
	if (convToDouble == 0)
	{
		return 0;
	}
	else
	{
		return convToDouble;
	}
}
//returns the dynamic array of doubles
////or NULL if the input string is wrong
//'str' contains doubles sepatated with ';'
//the value of 'size' is the number of elements in array
double *txt2double(const char *str, int *size) {
	int numOfElem = 0; //number of elements in final array
	double *res = (double*)calloc(numOfElem,sizeof(double));
	char *wordBeg = str;//the beginning of the string between separators
	char *wordEnd = str;//the end of the string between separators
	while ((*wordEnd != '\0'))
	{
		while ((*wordEnd != ';') && (*wordEnd != '\0')) wordEnd++;
		if (wordBeg == wordEnd)
		{
			*size = 0;//2 separators in a row, wrong input
			return NULL;
		}
		else
		{
			char *currWord = mkStrFromTo(wordBeg, wordEnd - 1);//make string between separators

			double dToAdd = processWord(currWord);//converting string to double
			if (dToAdd != 0) {
				res = (double*)realloc(res, (++numOfElem)*sizeof(double));
				res[numOfElem-1] = dToAdd;
			}
			else
			{
				*size = 0;
				return NULL;
			}
			
			if (wordEnd == '\0') break;
			else
			{
				wordEnd++;
				wordBeg = wordEnd;
			}
		}

	}
	*size = numOfElem;
	return res;
}
