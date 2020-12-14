#include "mylib.h"

int main(int argc, char *argv[]){
	int database[DATABASE_TYPE][DATABASE_NUMBER];
	// if (!database_init(database))
	// 	return (1);
	if (argc == 2 && !strcmp(argv[1], "-r"))
		random_inquiry(DATABASE_TYPE, DATABASE_NUMBER, database);
	else
		inquiry();
	return (0);
}
