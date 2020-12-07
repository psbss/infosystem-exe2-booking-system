#include "mylib.h"

int	inquiry(void)
{
	// int patient_no;
	int issue_part;
	int date;
	int ampm;

	// !! Must Validate !!
	while (1)
	{
		printf("\n診察予定部位を入力してください\n頭 : 1\n手足 : 2\n胸部, 腹部 : 3\n予防接種 : 4\n予約キャンセル : 5\n");
		scanf("%d", &issue_part);
		// Validate int 1-5
		if (validate_int(1, 5, issue_part))
			break;
		print_validation_err(issue_part);
	}

	while (1)
	{
		printf("\n診察希望日時(YYYYMMDD)を入力してください\nなお、翌日以降1週間での受付となります\n例 : 2020年12月31日 -> 20201231\n");
		scanf("%d", &date);
		// Validate int today-1week
		if (validate_date(7, date))
			break;
		print_validation_err(date);
	}

	while (1)
	{
		printf("\n希望の時間帯を入力してください\n午前 : 1\n午後 : 2\n");
		scanf("%d", &ampm);
		// Validate int 1-2
		if (validate_int(1, 2, ampm))
			break;
		print_validation_err(ampm);
	}

	return (0);
}

int	validate_int(int input_range_beginning, int input_range_end, int input)
{
	if (input_range_beginning <= input && input <= input_range_end)
		return (1); // true
	return (0); // false
}

// 現在の日付を元にバリデーションを行う
int	validate_date(int range_end, int input)
{
	time_t current_time = time(NULL);
	struct tm tm;
	localtime_r(&current_time, &tm);
	int current_time_int = (tm.tm_year + 1900) * 10000 + (tm.tm_mon + 1) * 100 + (tm.tm_mday);
	if (current_time_int < input && input <= current_time_int + range_end)
		return (1);
	return (0);
	// 休館判定は未考慮
}

void	print_validation_err(int input)
{
	printf("\n%d は対象外の数値です。再度入力してください。\n", input);
}

int	random_inquiry(int **database){
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
