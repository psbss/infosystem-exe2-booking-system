#include "mylib.h"

void database_init(int db_type, int db_no, int database[db_type][db_no]){
	// database : 
	//  - 患者No
	//  - issue_part
	//  - date
	//  - ampm
	//  - 診察時間
	//  - 施術時間

	int ct_type = 0;
	int ct_no = 0;

	while (ct_type < db_type)
	{
		ct_no = 0;
		while (ct_no < db_no)
		{
			database[ct_type][ct_no] = 0;
			ct_no++;
		}
		ct_type++;
	}
}
