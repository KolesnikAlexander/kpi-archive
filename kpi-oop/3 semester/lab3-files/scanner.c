#include "scanner.h"
printRec(SCAN_INFO* rec) {
	printf("	%s\n",rec->manufacturer);
	printf("	%s\n",rec->model);
	printf("	%d\n", rec->year);
	printf("	%f\n", rec->price);
	printf("	%d\n", rec->x_size);
	printf("	%d\n", rec->y_size);
	printf("	%d\n", rec->optr);
}
int printDba(char *dbaPath) {
	int numOfScanners;
	int i;
	FILE *dba;
	SCAN_INFO* scanner;

	if ((dba = fopen(dbaPath, "r+")) == NULL)
		return -1;
	fseek(dba, 0, SEEK_SET);
	fread(&numOfScanners, sizeof(int), 1, dba);

	scanner = (SCAN_INFO*)malloc(sizeof(SCAN_INFO));
	printf("		DBA FILE:\n");
	for (i = 0; i < numOfScanners; i++) {
		fread(scanner, sizeof(SCAN_INFO), 1, dba);
		printf("%d.", i + 1);
		printRec(scanner);
	}
}

SCAN_INFO *scanInfoConstructor(
	char manufacturer[127],//[127] изготовитель
	char model[128],// наименование модели
	int year,	 // год изготовления
	float price,// цена
	int x_size,// горизонтальный размер области сканирования
	int y_size,// вертикальный размер области сканирования
	int optr, int num) // оптическое разрешение
{
	SCAN_INFO *scanner;

	if ((scanner = (SCAN_INFO*)malloc(sizeof(SCAN_INFO))) == NULL) //SCAN_INFO element creating
		return NULL;
	strcpy(scanner->manufacturer, manufacturer);
	scanner->year = year;
	strcpy(scanner->model, model);
	scanner->price = price;
	scanner->x_size = x_size;
	scanner->y_size = y_size;
	scanner->optr = optr;

	return scanner;
}
SCAN_INFO_CMP *scanInfoConstructorCmp(
	char manufacturer[127],//[127] изготовитель
	char model[128],// наименование модели
	int year,	 // год изготовления
	float price,// цена
	int x_size,// горизонтальный размер области сканирования
	int y_size,// вертикальный размер области сканирования
	int optr, int num) // оптическое разрешение
{
	SCAN_INFO *scanner;
	SCAN_INFO_CMP *cmpScanner;

	if ((scanner = (SCAN_INFO*)malloc(sizeof(SCAN_INFO))) == NULL) //SCAN_INFO element creating
		return NULL;
	strcpy(scanner->manufacturer, manufacturer);
	scanner->year = year;
	strcpy(scanner->model, model);
	scanner->price = price;
	scanner->x_size = x_size;
	scanner->y_size = y_size;
	scanner->optr = optr;
	
	cmpScanner = malloc(sizeof(SCAN_INFO) + sizeof(int));//SCAN_INFO_CMP element creating
	cmpScanner->elem = scanner;
	cmpScanner->number = num;

	return cmpScanner;
}


int writeInfoToDBA(FILE *dba, const SCAN_INFO *scanner, int numOfScanners) {
	fseek(&(*dba), 0, SEEK_SET);
	fwrite(&numOfScanners, sizeof(int), 1, dba);
	fseek(&(*dba), 0, SEEK_END);
	fwrite(scanner, sizeof(SCAN_INFO), 1, dba);
	return 0;
}
int writeCSVToDBA(const char *dbaPath, const char *csvPath) {
	FILE *dba;
	FILE *csv;
	SCAN_INFO *scanner= (SCAN_INFO*)malloc(sizeof(SCAN_INFO));
	int numOfScanners = 0;

	if ((csv = fopen(csvPath, "r")) == NULL) 
		return -1;
		
	if ((dba = fopen(dbaPath, "wb+")) == NULL) 
		return -1;
	while (!feof(csv))
	{
		fscanf(csv, "%[A-z0-9];%[A-z0-9];%d;%f;%d;%d;%d\n", scanner->manufacturer, scanner->model, &(scanner->year), &(scanner->price), &(scanner->x_size), &(scanner->y_size), &(scanner->optr));
		numOfScanners++;
		writeInfoToDBA(dba, scanner, numOfScanners);

	}
	free(scanner);
	fclose(dba);
	fclose(csv);
	return 0;
}


int make_index(char *dbaPath, char *field_name)
{
	FILE *idx, *dba;
	int numOfScanners=-1;
	SCAN_INFO *scanner = (SCAN_INFO*)malloc(sizeof(SCAN_INFO));

	if ((dba = fopen(dbaPath, "rb")) == NULL)
		return -1;
	
	fseek(dba, 0, SEEK_SET);
	fread(&numOfScanners, sizeof(int), 1, dba);


	SCAN_INFO_CMP **scanners =(SCAN_INFO_CMP**)calloc(numOfScanners, sizeof(SCAN_INFO_CMP*)); //creating an array to store the sequence of scanners
	int i = 0;

	for(i = 0; i < numOfScanners; i++)
	{
		fread(scanner, sizeof(SCAN_INFO), 1, dba);
		scanners[i] = scanInfoConstructorCmp(scanner->manufacturer, scanner->model, scanner->year, scanner->price, scanner->x_size, scanner->y_size, scanner->optr,i+1);
	
	}

	if (!strcmp(field_name, "manufacturer"))
		qsort(scanners, numOfScanners, sizeof(SCAN_INFO_CMP*), manufacturerCmp);
	else if (!strcmp(field_name, "year"))
		qsort(scanners, numOfScanners, sizeof(SCAN_INFO_CMP*), yearCmp);
	else if (!strcmp(field_name, "model"))
		qsort(scanners, numOfScanners, sizeof(SCAN_INFO_CMP*), modelCmp);
	else if (!strcmp(field_name, "price"))
		qsort(scanners, numOfScanners, sizeof(SCAN_INFO_CMP*), priceCmp);
	else if (!strcmp(field_name, "x_size"))
		qsort(scanners, numOfScanners, sizeof(SCAN_INFO_CMP*), xSizeCmp);
	else if (!strcmp(field_name, "y_size"))
		qsort(scanners, numOfScanners, sizeof(SCAN_INFO_CMP*), ySizeCmp);
	else if (!strcmp(field_name, "optr"))
		qsort(scanners, numOfScanners, sizeof(SCAN_INFO_CMP*), optrCmp);
	else
	{
		fclose(dba);
		return -1;
	}
		

	char *idxPath = malloc(127);
	strcat(strcpy(idxPath, field_name), ".idx");//creating a path to the .idx file
	if ((idx = fopen(idxPath, "w")) == NULL)
	{
		fclose(dba);
		return -1;
	}

	for (i = 0; i < numOfScanners; i++) // entering data to .idx file
		fprintf(idx, "%d", scanners[i]->number);

	fclose(dba);
	fclose(idx);

	return 0;

}
int manufacturerCmp(const void * a, const void * b)
{
	return strcmp((*(SCAN_INFO_CMP**)a)->elem->manufacturer, (*(SCAN_INFO_CMP**)b)->elem->manufacturer);
}
int modelCmp(const void * a, const void * b)
{
	return strcmp((*(SCAN_INFO_CMP**)a)->elem->model, (*(SCAN_INFO_CMP**)b)->elem->model);
}
int yearCmp(const void * a, const void * b)
{
	return 	(*(SCAN_INFO_CMP**)a)->elem->year - (*(SCAN_INFO_CMP**)b)->elem->year;
}
int priceCmp(const void * a, const void * b)
{
	if ((*(SCAN_INFO_CMP**)a)->elem->price > (*(SCAN_INFO_CMP**)b)->elem->price)
		return 1;

	else if ((*(SCAN_INFO_CMP**)a)->elem->price < (*(SCAN_INFO_CMP**)b)->elem->price)
		return -1;

	else return 0;
}
int xSizeCmp(const void * a, const void * b)
{
	return 	(*(SCAN_INFO_CMP**)a)->elem->x_size - (*(SCAN_INFO_CMP**)b)->elem->x_size;
}
int ySizeCmp(const void * a, const void * b)
{
	return 	(*(SCAN_INFO_CMP**)a)->elem->y_size - (*(SCAN_INFO_CMP**)b)->elem->y_size;
}
int optrCmp(const void * a, const void * b)
{
	return 	(*(SCAN_INFO_CMP**)a)->elem->optr - (*(SCAN_INFO_CMP**)b)->elem->optr;
}

RECORD_SET *get_recs_by_index(char *path_dba, char *indx_field) {
	FILE *idx, *dba;
	char *idxPath = malloc(127);
	int i = 0;
	int numOfScanners = 0;
	int *idxArray;
	
	strcat(strcpy(idxPath, indx_field), ".idx");//creating a path to the .idx file
		
	if ((dba = fopen(path_dba, "rb")) == NULL)
			return NULL;
	if ((idx = fopen(idxPath, "r")) == NULL)
		return NULL;

	
	fseek(dba, 0, SEEK_SET);
	fread(&numOfScanners, sizeof(int), 1, dba);
	idxArray = calloc(numOfScanners, sizeof(int));

	for (i = 0; i < numOfScanners; i++) // reading data from .idx file
		fscanf(idx, "%1d", &idxArray[i]);

	RECORD_SET *set = (RECORD_SET*)malloc(sizeof(RECORD_SET));
	set->rec_nmb = numOfScanners;
	SCAN_INFO *scanners =(SCAN_INFO*) calloc(numOfScanners, sizeof(SCAN_INFO));

	for (i = 0; i < numOfScanners; i++){
		fseek(dba, sizeof(int)+(idxArray[i]-1)*sizeof(SCAN_INFO), SEEK_SET);
		fread(&scanners[i], sizeof(SCAN_INFO), 1, dba);
	}
	set->recs = scanners;

	fclose(dba);
	fclose(idx);
	return set;

}
void reindex(char *path_dba) {
	if (make_index(path_dba, "manufacturer"))
		printf("ERROR");

	if (make_index(path_dba, "year"))
		printf("ERROR");

	if (make_index(path_dba, "model"))
		printf("ERROR");

	if (make_index(path_dba, "price"))
		printf("ERROR");

	if (make_index(path_dba, "x_size"))
		printf("ERROR");

	if (make_index(path_dba, "y_size"))
		printf("ERROR");

	if (make_index(path_dba, "optr"))
		printf("ERROR");
}
int del_scan(char *path_dba, int n) {
	FILE *dba;
	SCAN_INFO *scanner;
	int i;
	int numOfScanners;

	if ((dba = fopen(path_dba, "r+")) == NULL)
		return -1;

	scanner = (SCAN_INFO*)malloc(sizeof(SCAN_INFO));

	fseek(dba, 0, SEEK_SET);
	fread(&numOfScanners, sizeof(int), 1, dba);

	if ((n < 1) || (n > numOfScanners))
		return -1;

	SCAN_INFO *scanners = (SCAN_INFO*)calloc(numOfScanners, sizeof(SCAN_INFO));
	for (i = 0; i < numOfScanners; i++) {
		fread(&scanners[i], sizeof(SCAN_INFO), 1, dba);
	}
	
	fclose(dba);
	if ((dba = fopen(path_dba, "w")) == NULL) //clear file
		return -1;
	numOfScanners--;
	fseek(dba, 0, SEEK_SET);
	fwrite(&numOfScanners, sizeof(int), 1, dba);

	for (i = 0; i < numOfScanners; i++) {
		if (i + 1 == n) {
			continue;
		}
		else
			fwrite(&scanners[i], sizeof(SCAN_INFO), 1, dba);
	}
	fclose(dba);
	return 0;
}
int writeToTXT(SCAN_INFO* rec, const char *txtPath) {
	FILE *txt;

	if ((txt = fopen(txtPath, "a")) == NULL)
		return -1;

	fwrite(&(rec->manufacturer), 1+sizeof(strlen(rec->manufacturer)), 1, txt);
	fprintf(txt, ";");
	fprintf(txt, "%s", rec->model);
	fprintf(txt, ";");
	fprintf(txt, "%d", rec->year);
	fprintf(txt, ";");
	fprintf(txt, "%f", rec->price);
	fprintf(txt, ";");
	fprintf(txt, "%d", rec->x_size);
	fprintf(txt, ";");
	fprintf(txt, "%d", rec->y_size);
	fprintf(txt, ";");
	fprintf(txt, "%d\n", rec->optr);
	fclose(txt);

}
int scanners_by_maxprice(char *path_dba, char *path_txt, float price) {
	int numOfScanners;
	int i;
	FILE *dba;
	SCAN_INFO* scanner;

	if ((dba = fopen(path_dba, "r+")) == NULL)
		return -1;

	fseek(dba, 0, SEEK_SET);
	fread(&numOfScanners, sizeof(int), 1, dba);
		
	FILE *txt;         //clear .txt file
	if ((txt = fopen(path_txt, "w")) == NULL)
			return -1;

	scanner = (SCAN_INFO*)malloc(sizeof(SCAN_INFO));
	for (i = 0; i < numOfScanners; i++) {
		fread(scanner, sizeof(SCAN_INFO), 1, dba);
		if ((scanner->price) <= price)
			writeToTXT(scanner, path_txt);
	}
	fclose(dba);
}
