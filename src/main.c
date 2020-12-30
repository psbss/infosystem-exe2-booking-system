#include "mylib.h"

int main(int argc, char *argv[]){
	printf("program started \n");
	int database[DATABASE_NUMBER][DATABASE_TYPE];
	double_array_init(DATABASE_NUMBER, DATABASE_TYPE, database);

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
