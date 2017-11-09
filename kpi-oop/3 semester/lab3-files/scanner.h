#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char manufacturer[127];// изготовитель
	int year;	 // год изготовления
	char model[128];// наименование модели
	float price;// цена
	int x_size;// горизонтальный размер области сканирования
	int y_size;// вертикальный размер области сканирования
	int optr; // оптическое разрешение
} SCAN_INFO;
typedef struct {
	SCAN_INFO *elem;
	int number;
} SCAN_INFO_CMP;


typedef struct {
	int rec_nmb;		// number of records
	SCAN_INFO *recs;	// records 
} RECORD_SET;

int writeInfoToDBA(FILE *dba, const SCAN_INFO *rec, int numOfScanners); // 1
int writeCSVToDBA(const char *path_dba, const char *path_csv); // 2

int printDba(char *dbaPath);
int manufacturerCmp(const void *val1, const void *val2);
int yearCmp(const void *a, const void *b);
int modelCmp(const void *a, const void *b);
int priceCmp(const void *a, const void *b);
int xSizeCmp(const void *a, const void *b);
int ySizeCmp(const void *a, const void *b);
int optrCmp(const void *a, const void *b);

int make_index(char *path_dba, char *field_name); 
RECORD_SET *get_recs_by_index(char *path_dba, char *indx_field);
void reindex(char *path_dba); 
int del_scan(char *path_dba, int n);
int scanners_by_maxprice(char *path_dba, char *path_txt, float price);