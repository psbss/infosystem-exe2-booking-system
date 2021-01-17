#include "mylib.h"

// 二次元配列の初期化を行う
// db_no:行数, db_type:列数, arr:Array
void double_array_init(int db_no, int db_type, int arr[db_no][db_type]){
	
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

void array_init(int no, int arr[no]){
	int ct = 0;
	while (ct < no)
	{
		arr[ct] = 0;
		ct++;
	}
}

// 乱数を返す
// rand_start:乱数の最小値, rand_end:乱数の最大値
int	get_rand(int rand_start, int rand_end){
	int random = 0;

	random = rand_start + rand() % (rand_end - rand_start + 1);
	return (random);
}

int len_arr(int types, int arr[][types]){
	int ct = 0;
	while (arr[ct][0] != '\0'){
		ct++;
	}
	return ct;
}

void insert_arr(int types, int new_arr_row, int old_arr_row, int arr[][types], int arr_new[][types]){
	int ct = 0;

	while (ct < types)
	{
		arr_new[new_arr_row][ct] = arr[old_arr_row][ct];
		ct++;
	}
}
		
// int型要素の入れ替えを行う
// x/y:入れ替える要素
void swap_int(int *x, int *y){
	int temp = 0;

	temp = *x;
	*x = *y;
	*y = temp;
}

// int型要素の配列の行入れ替え行う
// types:列数, _x/_y:入れ替える行番号, x/y:Array
void swap_arr_int(int types, int _x, int _y, int x[][types], int y[][types]){
	int temp_arr[types];
	int ct = 0;
	
	while (ct < types)
	{
		temp_arr[ct] = x[_x][ct];
		x[_x][ct] = y[_y][ct];
		y[_y][ct] = temp_arr[ct];
		ct++;
	}
}

void separate_arr(int types, int block_types, int _type, int db[][types], int db_mon_am[][types], int db_mon_pm[][types], int db_tue_am[][types], int db_tue_pm[][types], int db_thu_am[][types], int db_thu_pm[][types], int db_sat_am[][types], int db_sat_pm[][types]){
	int ct = 0;
	int ct_mon_am = 0;
	int ct_mon_pm = 0;
	int ct_tue_am = 0;
	int ct_tue_pm = 0;
	int ct_thu_am = 0;
	int ct_thu_pm = 0;
	int ct_sat_am = 0;
	int ct_sat_pm = 0;
	int today = get_time_now();
	printf("Today is %d---\n", today);
	while (ct < DATABASE_NUMBER)
	{
		if (db[ct][_type] == today + 1)
		{
			if (db[ct][_type + 1] == 1)
			{
				insert_arr(types, ct_mon_am, ct, db, db_mon_am);
				ct_mon_am++;
				db_mon_am[0][block_types - 1] = ct_mon_am;
			}
			else
			{
				insert_arr(types, ct_mon_pm, ct, db, db_mon_pm);
				ct_mon_pm++;
				db_mon_pm[0][block_types - 1] = ct_mon_pm;
			}
		}
		else if (db[ct][_type] == today + 2)
		{
			if (db[ct][_type + 1] == 1)
			{
				insert_arr(types, ct_tue_am, ct, db, db_tue_am);
				ct_tue_am++;
				db_tue_am[0][block_types - 1] = ct_tue_am;
			}
			else
			{
				insert_arr(types, ct_tue_pm, ct, db, db_tue_pm);
				ct_tue_pm++;
				db_tue_pm[0][block_types - 1] = ct_tue_pm;
			}
		}
		else if (db[ct][_type] == today + 3)
		{
			if (db[ct][_type + 1] == 1)
			{
				insert_arr(types, ct_thu_am, ct, db, db_thu_am);
				ct_thu_am++;
				db_thu_am[0][block_types - 1] = ct_thu_am;
			}
			else
			{
				insert_arr(types, ct_thu_pm, ct, db, db_thu_pm);
				ct_thu_pm++;
				db_thu_pm[0][block_types - 1] = ct_thu_pm;
			}
		}
		else if (db[ct][_type] == today + 4)
		{
			if (db[ct][_type + 1] == 1)
			{
				insert_arr(types, ct_sat_am, ct, db, db_sat_am);
				ct_sat_am++;
				db_sat_am[0][block_types - 1] = ct_sat_am;
			}
			else
			{
				insert_arr(types, ct_sat_pm, ct, db, db_sat_pm);
				ct_sat_pm++;
				db_sat_pm[0][block_types - 1] = ct_sat_pm;
			}
		}
		ct++;
	}
}

int get_time_now(void){
	time_t current_time = time(NULL);
	struct tm Time;
	localtime_r(&current_time, &Time);
	return ((Time.tm_year + 1900) * 10000 + (Time.tm_mon + 1) * 100 + (Time.tm_mday));
}

int arr_len(int type, int arr[][type]){
	int ct = 0;

	while(arr[ct][2] != 0)
		ct++;
	return (ct);
}

// 診察・施術時間
void add_exeopetime(int types, int _type, int _exe, int _ope, int no, int arr[][types]){
	int ct = 0;
	int issue_part = 0;
	while (ct < no)
	{
		issue_part = arr[ct][_type];
		if (issue_part == 1)
		{
			arr[ct][_exe] = 5;
			arr[ct][_ope] = 0;
		} else if (issue_part == 2) {
			arr[ct][_exe] = 10;
			arr[ct][_ope] = 15;
		} else if (issue_part == 3) {
			arr[ct][_exe] = 10;
			arr[ct][_ope] = 0;
		} else if (issue_part == 4) {
			arr[ct][_exe] = 12;
			arr[ct][_ope] = 5;
		}
		ct++;
	}
}

void print_result(int no, int arr[]){
	int ct = 0;
	while (ct < no)
	{
		if (ct != 0)
			printf(" -> ");
		printf("%d", arr[ct]);
		ct++;
	}
	printf("\n");
}

void print_result_withid(int no, int arr[], int id[]){
	int ct = 0;
	while (ct < no)
	{
		if (ct != 0)
			printf(" -> ");
		printf("%d", id[arr[ct]]);
		ct++;
	}
	printf("\n");
}

void arr_index_init(int no, int arr[]){
	int ct = 0;
	while (ct < no)
	{
		arr[ct] = ct;
		ct++;
	}
}

void arr_double_index_init(int types, int _type, int no, int arr[][types]){
	int ct = 0;
	while (ct < no)
	{
		arr[ct][_type] = ct;
		ct++;
	}
}

void arr_copy(int types, int no, int _type, int arr[][types], int dist[]){
	int ct = 0;
	while (ct < no)
	{
		dist[ct] = arr[ct][_type];
		ct++;
	}
}
