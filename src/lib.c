#include "mylib.h"

int** database_init(int **database){
	if (!(database = (int **)malloc(sizeof(int *) * 6)))
		return (NULL);
	int countroop = 0;
	while (1)
	{
		if (!(database[countroop] = (int *)malloc(sizeof(int *) * 32)))
			return (NULL);
		if (++countroop > 32)
			break;
	}
	while (--countroop > 0)
		memset(*database, 0, 6);
	return (database);
}

// database : 
//  - 患者No
//  - issue_part
//  - date
//  - ampm
//  - 診察時間
//  - 施術時間
