#include "mylib.h"

int main(int argc, char *argv[]){
	int **database;
	if (!database_init(database))
		return (NULL);
	if (argc == 2 && !strcmp(argv[1], "-r"))
		random_inquiry(database);
	else
		inquiry();
	return (0);
}
