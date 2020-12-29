#include "mylib.h"

void database_printf(int db_no, int db_type, int arr[db_no][db_type]){
	// Show database
	int ct_type = 0;
	int ct_no = 0;

	printf("\n\n");
	while (ct_no < db_no)
	{
		ct_type = 0;
		while (ct_type < db_type)
		{
			printf("%d ", arr[ct_no][ct_type]);
			ct_type++;
		}
		putchar('\n');
		ct_no++;
	}
}
