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
	database_init(DATABASE_NUMBER, DATABASE_TYPE, database);
	database_init(DATABASE_BLOCK_NUMBER, DATABASE_TYPE, db_mon_am);
	database_init(DATABASE_BLOCK_NUMBER, DATABASE_TYPE, db_mon_pm);
	database_init(DATABASE_BLOCK_NUMBER, DATABASE_TYPE, db_tue_am);
	database_init(DATABASE_BLOCK_NUMBER, DATABASE_TYPE, db_tue_pm);
	database_init(DATABASE_BLOCK_NUMBER, DATABASE_TYPE, db_thu_am);
	database_init(DATABASE_BLOCK_NUMBER, DATABASE_TYPE, db_thu_pm);
	database_init(DATABASE_BLOCK_NUMBER, DATABASE_TYPE, db_sat_am);
	database_init(DATABASE_BLOCK_NUMBER, DATABASE_TYPE, db_sat_pm);

	printf("database_init finished! \n");

	if (argc == 2 && !strcmp(argv[1], "-r")){
		random_inquiry(DATABASE_NUMBER, DATABASE_TYPE, database);
		printf("random_inquiry finished! \n");
	} else {
		inquiry();
		printf("inquiry finished! \n");
	}
	database_printf(DATABASE_NUMBER, DATABASE_TYPE, database);
	return (0);
}
