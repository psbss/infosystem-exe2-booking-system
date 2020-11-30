#include "mylib.h"

int	random_inquiry(void){
	int issue_part;
	int date;
	int ampm;
	time_t current_time = time(NULL);

	struct tm Time;
	localtime_r(&current_time, &Time);
	int current_time_int = (Time.tm_year + 1900) * 10000 + (Time.tm_mon + 1) * 100 + (Time.tm_mday);

	issue_part = get_rand(1.0, 5.0);
	date = current_time_int + get_rand(1.0, 7.0);
	ampm = get_rand(1.0, 2.0);

	return (0);
}

int	get_rand(double rand_start, double rand_end){
	time_t current_time = time(NULL);
	// init random
	srand((unsigned int)current_time);

	return (rand_start + (int)((rand_end - rand_start + 1.0) * rand() / (RAND_MAX + 1.0)));
}