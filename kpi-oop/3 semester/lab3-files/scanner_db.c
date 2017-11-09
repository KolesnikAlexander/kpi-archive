#include "scanner.h"

int main() {
	int NUM_TO_DEL = 3;
	float MAX_PRICE = 320;
	char GET_RECS_BY_INDEX_WORD[] = "manufacturer";
	char dbaPath[] = "Data/Scanners.dba";
	char csvPath[] = "Data/Scanners.csv";
	char txtPath[] = "scannersByMaxPrice.txt";


	RECORD_SET *set;
	int i;
	//writeCSVToDBA() test
	printf("___________________________\n");
	printf("writeCSVToDBA() test\n");
	printf("___________________________\n");
	writeCSVToDBA(dbaPath, csvPath);
	printDba(dbaPath);

	//scanners_by_maxprice() test
	printf("___________________________\n");
	printf("scanners_by_maxprice() test\n");
	printf("___________________________\n");
	scanners_by_maxprice(dbaPath, txtPath, MAX_PRICE);
	printf("Result is in file %s\n", txtPath);

	//reindex() test
	printf("___________________________\n");
	printf("reindex() test\n");
	printf("___________________________\n");
	reindex(dbaPath);
	printf("Indexation is done\n");

	//get_recs_by_index() test
	printf("___________________________\n");
	printf("get_recs_by_index() test\n");
	printf("___________________________\n");
	printf("FOR file %s.idx\n", GET_RECS_BY_INDEX_WORD);
	
	if ((set = get_recs_by_index(dbaPath, GET_RECS_BY_INDEX_WORD)) != NULL) {
		for (i = 0; i < set->rec_nmb; i++) { //test
			printf("%s\n", set->recs[i].manufacturer);
		}
	}
	else
	{
		printf("ERROR\n");
	}
	//del_scan() test
	NUM_TO_DEL = 3;
	printf("___________________________\n");
	printf("del_scan() test\n");
	printf("___________________________\n");
	printf("Delete %d element\n",NUM_TO_DEL);
	printf("		BEFORE\n");
	printDba(dbaPath);

	if (del_scan(dbaPath, NUM_TO_DEL)) {
		printf("ERROR\n");
	}
	else
	{
		printf("		AFTER\n");
		reindex(dbaPath);
		printDba(dbaPath);
	}
	
	
	return 0;
}