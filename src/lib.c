#include "mylib.h"

void database_init(int db_no, int db_type, int database[db_no][db_type]){
	// database : 
	//  - 患者No
	//  - issue_part
	//  - date
	//  - ampm
	//  - 診察時間
	//  - 施術時間

	int ct_type = 0;
	int ct_no = 0;

	while (ct_no < db_no)
	{
		ct_type = 0;
		while (ct_type < db_type)
		{
			database[ct_no][ct_type] = 0;
			ct_type++;
		}
		ct_no++;
	}
}
