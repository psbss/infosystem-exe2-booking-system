#include "mylib.h"

int	random_inquiry(void){
	int issue_part;
	int date;
	int ampm;
	time_t current_time = time(NULL);

	struct tm Time;
	localtime_r(&current_time, &Time);
	int current_time_int = (Time.tm_year + 1900) * 10000 + (Time.tm_mon + 1) * 100 + (Time.tm_mday);

	// get_rand(rand_start, rand_end)
	// rand_start < rand_end
	issue_part = get_rand(current_time, 1.0, 5.0);
	date = current_time_int + get_rand(current_time, 1.0, 7.0);
	ampm = get_rand(current_time, 1.0, 2.0);

	return (0);
}

int	get_rand(time_t current_time, double rand_start, double rand_end){
	// rand() % max を利用した方法は乱数として数値の余りを利用しているため偏りが発生する。
	// get_rand を利用することで、擬似乱数として本質的に乱数に近い数値を返すことが可能である。

	// init random
	srand((unsigned int)current_time);
	// current_time を関数実行時に変更すると乱数生成が失敗するため、呼び出し元から時間を引き継いで初期化している。

	return ((int)rand_start + (int)((rand_end - rand_start + 1.0) * rand() / (RAND_MAX + 1.0)));
}