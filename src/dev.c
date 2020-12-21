#include "mylib.h"

void database_printf(int db_type, int db_no, int database[db_type][db_no]){
	// Show database
	int ct_type = 0;
	int ct_no = 0;

	while (ct_type < db_type)
	{
		ct_no = 0;
		while (ct_no < db_no)
		{
			printf("%d", database[ct_type][ct_no]);
			ct_no++;
		}
		ct_type++;
	}
}
