#include "mylib.h"

// 配列の中身を表示する
// arr_no:行数, arr_type:列数, arr:Array
void print_double_arr(int arr_no, int arr_type, int arr[arr_no][arr_type]){
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
	while (ct_no < arr_no)
	{
		ct_type = 0;
		printf("%d: ", ct);
		while (ct_type < arr_type)
		{
			printf("%d ", arr[ct_no][ct_type]);
			ct_type++;
		}
		putchar('\n');
		ct_no++;
		ct++;
	}
}

void print_arr(int type, int arr[]){
	int ct = 0;

	while (ct < type)
	{
		printf("%d:%d\n", ct, arr[ct]);
		ct++;
	}
}

void print_newline(int n){
	while(n--)
		printf("\n");
}
