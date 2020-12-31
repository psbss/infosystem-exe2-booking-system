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

void insert_arr(int types, int new_arr_row, int old_arr_row, int arr[][types], int arr_new[][types]){
	int ct = 0;

	while (ct < types)
	{
		arr_new[new_arr_row][ct] = arr[old_arr_row][ct];
		ct++;
	}
}

void separate_arr(int types, int _type, int db[][types], int db_mon_am[][types], int db_mon_pm[][types], int db_tue_am[][types], int db_tue_pm[][types], int db_thu_am[][types], int db_thu_pm[][types], int db_sat_am[][types], int db_sat_pm[][types]){
	int ct = 0;
	int ct_am = 0;
	int ct_pm = 0;
	int today = 20201232;

	while (ct < DATABASE_NUMBER)
	{
		ct_am = 0;
		ct_pm = 0;
		if (db[ct][_type] == today)
		{
			if (db[ct][_type + 1] == 1)
			{
				insert_arr(types, ct_am, ct, db, db_mon_am);
				ct_am++;
			}
			else
			{
				insert_arr(types, ct_pm, ct, db, db_mon_pm);
				ct_pm++;
			}
		}
		else if (db[ct][_type] == today + 1)
		{
			if (db[ct][_type + 1] == 1)
			{
				insert_arr(types, ct_am, ct, db, db_tue_am);
				ct_am++;
			}
			else
			{
				insert_arr(types, ct_pm, ct, db, db_tue_pm);
				ct_pm++;
			}
		}
		else if (db[ct][_type] == today + 2)
		{
			if (db[ct][_type + 1] == 1)
			{
				insert_arr(types, ct_am, ct, db, db_thu_am);
				ct_am++;
			}
			else
			{
				insert_arr(types, ct_pm, ct, db, db_thu_pm);
				ct_pm++;
			}
		}
		else if (db[ct][_type] == today + 3)
		{
			if (db[ct][_type + 1] == 1)
			{
				insert_arr(types, ct_am, ct, db, db_sat_am);
				ct_am++;
			}
			else
			{
				insert_arr(types, ct_pm, ct, db, db_sat_pm);
				ct_pm++;
			}
		}
		ct++;
	}

	return _type;
}
