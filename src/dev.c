#include "mylib.h"

void database_printf(int db_no, int db_type, int database[db_no][db_type]){
	// Show database
	int ct_type = 0;
	int ct_no = 0;

	while (ct_type < db_no)
	{
		ct_no = 0;
		while (ct_no < db_type)
		{
			printf("%d ", database[ct_type][ct_no]);
			ct_no++;
		}
		putchar('\n');
		ct_type++;
	}
}
