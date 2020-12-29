#include "mylib.h"

void array_init(int db_no, int db_type, int arr[db_no][db_type]){
	
	int ct_type = 0;
	int ct_no = 0;

	while (ct_no < db_no)
	{
		ct_type = 0;
		while (ct_type < db_type)
		{
			arr[ct_no][ct_type] = 0;
			ct_type++;
		}
		ct_no++;
	}
}

int	get_rand(int rand_start, int rand_end){
	int random = 0;

	random = rand_start + rand() % (rand_end - rand_start + 1);

	return (random);
}
