#include "mylib.h"

// クイックソート
// arr:Array, lower:最小にする数値, bigger:最大にする数値
void quick_sort(int arr[], int lower, int bigger){
	int pivot = 0;

	if (lower < bigger)
	{
		pivot = partition(arr, lower, bigger);
		quick_sort(arr, lower, pivot - 1);
		quick_sort(arr, pivot + 1, bigger);
	}
}

// quick_sort のパーティションを選定する
// arr:Array, lower:最小にする数値, bigger:最大にする数値
int partition(int arr[], int lower, int bigger){
	int pivot = arr[bigger];
	int i = lower - 1;
	int j = lower;

	while (j <= bigger - 1)
	{
		if (arr[j] <= pivot)
		{
			i++;
			swap_int(&arr[i], &arr[j]);
		}
		j++;
	}
	swap_int(&arr[i + 1], &arr[bigger]);
	return (i + 1);
}

// 二次元配列 列用クイックソート
// types:列数, _type:入れ替える列, lower:最小値, bigger:最大値, arr:Array
void quick_sort_double_arr(int types, int _type, int lower, int bigger, int arr[][types]){
	int pivot = 0;

	if (lower < bigger)
	{
		pivot = partition_double_arr(types, _type, lower, bigger, arr);
		quick_sort_double_arr(types, _type, lower, (pivot - 1), arr);
		quick_sort_double_arr(types, _type, (pivot + 1), bigger, arr);
	}
}

// quick_sort_double_arr のパーティションを選定する
// types:列数, _type:入れ替える列, lower:最小値, bigger:最大値, arr:Array
int partition_double_arr(int types, int _type, int lower, int bigger, int arr[][types]){
	int pivot = arr[bigger][_type];
	int i = (lower - 1);
	int j = lower;

	while (j <= bigger - 1)
	{
		if (arr[j][_type] <= pivot)
		{
			i++;
			swap_arr_int(types ,i ,j ,arr ,arr);
		}
		j++;
	}
	swap_arr_int(types, (i + 1), bigger, arr, arr);
	return (i + 1);
}

// バブルソート
// types:列数, arr:Array
void bobble_sort(int types, int arr[]){
	int ct_i = 0;
	int ct_j = 0;
	
	while(ct_i < types - 1)
	{
		ct_j = types - 1;
		while (ct_j >= ct_i + 1)
		{
			if (arr[ct_j] < arr[ct_j - 1])
				swap_int(&arr[ct_j], &arr[ct_j - 1]);
			ct_j--;
		}
		ct_i++;
	}
}

// 二次元配列 列用バブルソート
// types:列数, _type:入れ替える列, no:行数, arr:Array
void bobble_sort_double_arr(int types, int _type, int no, int arr[][types]){
	int ct_i = 0;
	int ct_j = 0;
	
	while(ct_i < no - 1)
	{
		ct_j = no - 1;
		while (ct_j >= ct_i + 1)
		{
			if (arr[ct_j][_type] < arr[ct_j - 1][_type])
				swap_arr_int(types, ct_j, ct_j - 1, arr, arr);
			ct_j--;
		}
		ct_i++;
	}
}
