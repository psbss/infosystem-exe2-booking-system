#include "mylib.h"

int main(int argc, char *argv[]){
	printf("program started \n");
	int database[DATABASE_NUMBER][DATABASE_TYPE];
	int db_mon_am[DATABASE_BLOCK_NUMBER][DATABASE_BLOCK_TYPE];
	int db_mon_pm[DATABASE_BLOCK_NUMBER][DATABASE_BLOCK_TYPE];
	int db_tue_am[DATABASE_BLOCK_NUMBER][DATABASE_BLOCK_TYPE];
	int db_tue_pm[DATABASE_BLOCK_NUMBER][DATABASE_BLOCK_TYPE];
	int db_thu_am[DATABASE_BLOCK_NUMBER][DATABASE_BLOCK_TYPE];
	int db_thu_pm[DATABASE_BLOCK_NUMBER][DATABASE_BLOCK_TYPE];
	int db_sat_am[DATABASE_BLOCK_NUMBER][DATABASE_BLOCK_TYPE];
	int db_sat_pm[DATABASE_BLOCK_NUMBER][DATABASE_BLOCK_TYPE];
	double_array_init(DATABASE_NUMBER, DATABASE_TYPE, database);
	double_array_init(DATABASE_BLOCK_NUMBER, DATABASE_BLOCK_TYPE, db_mon_am);
	double_array_init(DATABASE_BLOCK_NUMBER, DATABASE_BLOCK_TYPE, db_mon_pm);
	double_array_init(DATABASE_BLOCK_NUMBER, DATABASE_BLOCK_TYPE, db_tue_am);
	double_array_init(DATABASE_BLOCK_NUMBER, DATABASE_BLOCK_TYPE, db_tue_pm);
	double_array_init(DATABASE_BLOCK_NUMBER, DATABASE_BLOCK_TYPE, db_thu_am);
	double_array_init(DATABASE_BLOCK_NUMBER, DATABASE_BLOCK_TYPE, db_thu_pm);
	double_array_init(DATABASE_BLOCK_NUMBER, DATABASE_BLOCK_TYPE, db_sat_am);
	double_array_init(DATABASE_BLOCK_NUMBER, DATABASE_BLOCK_TYPE, db_sat_pm);
	printf("array_init finished! \n");

	if (argc == 2 && !strcmp(argv[1], "-r")){
		random_inquiry(DATABASE_NUMBER, DATABASE_TYPE, database);
		printf("random_inquiry finished! \n");
	} else {
		inquiry();
		printf("inquiry finished! \n");
	}

	bubble_sort_double_arr(DATABASE_TYPE, 2, DATABASE_NUMBER, database);
	printf("bubble sort finished \n");
	separate_arr(DATABASE_TYPE, DATABASE_BLOCK_TYPE, 2, database, db_mon_am, db_mon_pm, db_tue_am, db_tue_pm, db_thu_am, db_thu_pm, db_sat_am, db_sat_pm);
	printf("separate array finished \n");
	print_double_arr(DATABASE_NUMBER, DATABASE_TYPE, database);
	printf("%d %d %d", db_mon_am[1][0], db_mon_am[1][1], db_mon_am[1][2]);
	print_double_arr(DATABASE_BLOCK_NUMBER, DATABASE_BLOCK_TYPE, db_mon_am);

	return (0);
}
