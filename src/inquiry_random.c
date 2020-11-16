#include "mylib.h"

int	random_inquiry(void){
	int issue_part;
	int date;
	int ampm;
	time_t current_time = time(NULL);

	// init random
	srand((unsigned int)current_time);

	struct tm tm;
	localtime_r(&current_time, &tm);
	int current_time_int = (tm.tm_year + 1900) * 10000 + (tm.tm_mon + 1) * 100 + (tm.tm_mday);

	issue_part = 1 + rand() % 5;
	date = current_time_int + (1 + rand() % 7);
	ampm = 1 + rand() % 2;

	return (0);
}