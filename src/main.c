#include "mylib.h"

int main(int argc, char *argv[]){
	printf("program started \n");
	int database[DATABASE_NUMBER][DATABASE_TYPE];
	int db_mon_am[DATABASE_BLOCK_NUMBER][DATABASE_TYPE];
	int db_mon_pm[DATABASE_BLOCK_NUMBER][DATABASE_TYPE];
	int db_tue_am[DATABASE_BLOCK_NUMBER][DATABASE_TYPE];
	int db_tue_pm[DATABASE_BLOCK_NUMBER][DATABASE_TYPE];
	int db_thu_am[DATABASE_BLOCK_NUMBER][DATABASE_TYPE];
	int db_thu_pm[DATABASE_BLOCK_NUMBER][DATABASE_TYPE];
	int db_sat_am[DATABASE_BLOCK_NUMBER][DATABASE_TYPE];
	int db_sat_pm[DATABASE_BLOCK_NUMBER][DATABASE_TYPE];
	int db_mon_am_no = 0;
	int db_mon_pm_no = 0;
	int db_tue_am_no = 0;
	int db_tue_pm_no = 0;
	int db_thu_am_no = 0;
	int db_thu_pm_no = 0;
	int db_sat_am_no = 0;
	int db_sat_pm_no = 0;
	double_array_init(DATABASE_NUMBER, DATABASE_TYPE, database);
	double_array_init(DATABASE_BLOCK_NUMBER, DATABASE_TYPE, db_mon_am);
	double_array_init(DATABASE_BLOCK_NUMBER, DATABASE_TYPE, db_mon_pm);
	double_array_init(DATABASE_BLOCK_NUMBER, DATABASE_TYPE, db_tue_am);
	double_array_init(DATABASE_BLOCK_NUMBER, DATABASE_TYPE, db_tue_pm);
	double_array_init(DATABASE_BLOCK_NUMBER, DATABASE_TYPE, db_thu_am);
	double_array_init(DATABASE_BLOCK_NUMBER, DATABASE_TYPE, db_thu_pm);
	double_array_init(DATABASE_BLOCK_NUMBER, DATABASE_TYPE, db_sat_am);
	double_array_init(DATABASE_BLOCK_NUMBER, DATABASE_TYPE, db_sat_pm);

	printf("array_init finished! \n");

	if (argc == 2 && !strcmp(argv[1], "-r")){
		random_inquiry(DATABASE_NUMBER, DATABASE_TYPE, database);
		printf("random_inquiry finished! \n");
	} else {
		inquiry();
		printf("inquiry finished! \n");
	}
	
	bubble_sort_double_arr(DATABASE_TYPE, 2, DATABASE_NUMBER, database);
	separate_arr(DATABASE_TYPE, 2, database, db_mon_am, db_mon_pm, db_tue_am, db_tue_pm, db_thu_am, db_thu_pm, db_sat_am, db_sat_pm);
	print_double_arr(DATABASE_NUMBER, DATABASE_TYPE, database);
	print_double_arr(DATABASE_BLOCK_NUMBER, DATABASE_TYPE, db_mon_am);

	db_mon_am_no = arr_len(DATABASE_TYPE, db_mon_am);
	db_mon_pm_no = arr_len(DATABASE_TYPE, db_mon_pm);
	db_tue_am_no = arr_len(DATABASE_TYPE, db_tue_am);
	db_tue_pm_no = arr_len(DATABASE_TYPE, db_tue_pm);
	db_thu_am_no = arr_len(DATABASE_TYPE, db_thu_am);
	db_thu_pm_no = arr_len(DATABASE_TYPE, db_thu_pm);
	db_sat_am_no = arr_len(DATABASE_TYPE, db_sat_am);
	db_sat_pm_no = arr_len(DATABASE_TYPE, db_sat_pm);

	int sum[8];
	int arr[DATABASE_BLOCK_NUMBER];
	int arr2[DATABASE_BLOCK_NUMBER];
	array_init(8, sum);
	array_init(DATABASE_BLOCK_NUMBER, arr);	
	array_init(DATABASE_BLOCK_NUMBER, arr2);

	for (int i = 0; i < db_mon_am_no; i++)
	{
		arr[i] = db_mon_am[i][0];
		db_mon_am[i][0] = i;
		arr2[i] = i;
	}

	johnson(db_mon_am, 0, db_mon_am_no, arr2, sum);

	for (int i = 0; i < db_mon_am_no; i++)
	{
		printf("%d -> ", arr2[i]);
 	}

	return (0);
}
