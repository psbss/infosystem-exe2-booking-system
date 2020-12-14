#include "mylib.h"

int main(int argc, char *argv[]){
	int database[DATABASE_TYPE][DATABASE_NUMBER];
	database_init(DATABASE_TYPE, DATABASE_NUMBER, database);
	
	if (argc == 2 && !strcmp(argv[1], "-r"))
		random_inquiry(DATABASE_TYPE, DATABASE_NUMBER, database);
	else
		inquiry();
	return (0);
}
