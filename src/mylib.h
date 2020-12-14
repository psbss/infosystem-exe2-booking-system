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
int random_inquiry(int db_type, int db_no, int database[db_type][db_no]);
int get_rand(time_t current_time, double rand_start, double rand_end);

// lib
void database_init(int db_type, int db_no, int database[db_type][db_no]);

#endif
