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
	quick_sort_double_arr(6, 2, 0, DATABASE_NUMBER,  database);
	database_printf(DATABASE_NUMBER, DATABASE_TYPE, database);
	return (0);
}
