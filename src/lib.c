#include "mylib.h"

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

int	get_rand(int rand_start, int rand_end){
	int random = 0;

	random = rand_start + rand() % (rand_end - rand_start + 1);

	return (random);
}

void swap_int(int *x, int *y){
	int temp = 0;

	temp = *x;
	*x = *y;
	*y = temp;
}

// types:要素数, _X:入れ替える列番号, _y:入れ替える列番号, x/y:Array
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

void quick_sort(int arr[], int lower, int bigger){
	int pivot = 0;

	if (lower < bigger)
	{
		pivot = partition(arr, lower, bigger);
		quick_sort(arr, lower, pivot - 1);
		quick_sort(arr, pivot + 1, bigger);
	}
}
