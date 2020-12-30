#ifndef MYLIB_H
#define MYLIB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include <time.h>

// Define
#define DATABASE_TYPE 6	   // database で格納するデータの種類
#define DATABASE_NUMBER 32 // database で格納するデータの件数

int inquiry(void);
int validate_int(int input_range_beginning, int input_range_end, int input);
int validate_date(int range_end, int input);
void print_validation_err(int input);
void random_inquiry(int db_type, int db_no, int database[db_type][db_no]);
int get_rand(int rand_start, int rand_end);

void johnson(int database[][6], int start, int count, int *johnson, int *sumtime);

void double_array_init(int db_no, int db_type, int arr[db_no][db_type]);
void swap_int(int *x, int *y);
void swap_arr_int(int types, int _x, int _y, int x[][types], int y[][types]);
int partition(int arr[], int lower, int bigger);
void quick_sort(int arr[], int lower, int bigger);
void quick_sort_double_arr(int types, int lower, int bigger, int arr[][types]);

void database_printf(int db_no, int db_type, int arr[db_no][db_type]);

#endif
