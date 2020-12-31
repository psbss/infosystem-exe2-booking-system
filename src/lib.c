#include "mylib.h"

void database_init(int db_no, int db_type, int database[db_no][db_type]){
	// database : 
	//  - 患者No
	//  - issue_part
	//  - date
	//  - ampm
	//  - 診察時間
	//  - 施術時間

	int ct_type = 0;
	int ct_no = 0;

	while (ct_no < db_no)
	{
		ct_type = 0;
		while (ct_type < db_type)
		{
			database[ct_no][ct_type] = 0;
			ct_type++;
		}
		ct_no++;
	}
}

int	get_rand(int rand_start, int rand_end){
	int random = 0;

	random = rand_start + rand() % (rand_end - rand_start + 1);

	return (random);
}

int len_arr(int types, int arr[][types]){
	int ct = 0;
	while (arr[ct][0] != '\0'){
		ct++;
	}
	return ct;
}
