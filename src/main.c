#include "mylib.h"

int main(int argc, char *argv[]){
	int database[DATABASE_NUMBER][DATABASE_TYPE];
	database_init(DATABASE_NUMBER, DATABASE_TYPE, database);

	if (argc == 2 && !strcmp(argv[1], "-r"))
		random_inquiry(DATABASE_NUMBER, DATABASE_TYPE, database);
	else
		inquiry();
	database_printf(DATABASE_NUMBER, DATABASE_TYPE, database);
	return (0);
}
