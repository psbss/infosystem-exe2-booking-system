#ifndef MYLIB_H
#define MYLIB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include <time.h>

// database :
//  0: 患者No
//  1: issue_part
//  2: date
//  3: ampm
//  4: 診察時間
//  5: 施術時間

// Define
#define DATABASE_TYPE 6			 // database で格納するデータの種類
#define DATABASE_NUMBER 32		 // database で格納するデータの件数
#define DATABASE_BLOCK_NUMBER 11 // ブロック内で保持するデータ件数

int inquiry(void);
int validate_int(int input_range_beginning, int input_range_end, int input);
int validate_date(int range_end, int input);
void print_validation_err(int input);
void random_inquiry(int db_type, int db_no, int database[db_type][db_no]);
int get_rand(int rand_start, int rand_end);

void johnson(int database[][6], int start, int count, int *johnson, int *sumtime);

void double_array_init(int db_no, int db_type, int arr[db_no][db_type]);
void array_init(int no, int arr[no]);
int len_arr(int types, int arr[][types]);
int get_time_now(void);
void insert_arr(int types, int new_arr_row, int old_arr_row, int arr[][types], int arr_new[][types]);
void separate_arr(int types, int _type, int db[][types], int db_mon_am[][types], int db_mon_pm[][types], int db_tue_am[][types], int db_tue_pm[][types], int db_thu_am[][types], int db_thu_pm[][types], int db_sat_am[][types], int db_sat_pm[][types]);
void swap_int(int *x, int *y);
void swap_arr_int(int types, int _x, int _y, int x[][types], int y[][types]);
int partition(int arr[], int lower, int bigger);
void quick_sort(int arr[], int lower, int bigger);
int partition_double_arr(int types, int _type, int lower, int bigger, int arr[][types]);
void quick_sort_double_arr(int types, int _type, int lower, int bigger, int arr[][types]);
void bubble_sort(int types, int arr[]);
void bubble_sort_double_arr(int types, int _type, int no, int arr[][types]);
int arr_len(int type, int arr[][type]);
void add_exeopetime(int types, int _type, int _exe, int _ope, int no, int arr[][types]);
void print_result(int no, int arr[]);
void print_result_withid(int no, int arr[], int id[]);

void print_double_arr(int arr_no, int arr_type, int arr[arr_no][arr_type]);
void print_arr(int type, int arr[]);
void print_newline(int n);

#endif
