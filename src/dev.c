#include "mylib.h"

// 配列の中身を表示する
// db_no:行数, db_type:列数, arr:Array
void database_printf(int db_no, int db_type, int arr[db_no][db_type]){
	// Show database
	// database : 
	//  - 患者No
	//  - issue_part
	//  - date
	//  - ampm
	//  - 診察時間
	//  - 施術時間

	int ct = 0;
	int ct_type = 0;
	int ct_no = 0;
	char *database_head[6] = {
			"患者No",
			"診察部位",
			"日程",
			"診察希望時間帯",
			"診察時間",
			"施術時間"
		};

	printf("\n\n");
	while (ct_no < 6)
	{
		printf("%s ", database_head[ct_no]);
		ct_no++;
	}
	ct_no = 0;

	printf("\n");
	while (ct_no < db_no)
	{
		ct_type = 0;
		printf("%d: ", ct);
		while (ct_type < db_type)
		{
			printf("%d ", arr[ct_no][ct_type]);
			ct_type++;
		}
		putchar('\n');
		ct_no++;
		ct++;
	}
}
