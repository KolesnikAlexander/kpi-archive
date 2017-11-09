#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
int substr(const char *string1, const char *string2);
int subseq(const char *string1, const char *string2);
char ispol(const char *string);
char* makepal(const char *string);
double *txt2double(const char *str, int *size);