#ifndef MYLIB_H
#define MYLIB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include <time.h>

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

// johnson
void johnson(int database[][6], int start, int count, int* johnson, int* sumtime);

// lib
void database_init(int db_no, int db_type, int database[db_no][db_type]);
int len_arr(int types, int arr[][types]);

// dev
void database_printf(int db_no, int db_type, int database[db_no][db_type]);

#endif
