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
		printf("\n診察部位\n頭 : 1\n手足 : 2\n胸部, 腹部 : 3\n予防接種 : 4\n予約キャンセル : 5\n");
		scanf("%d", &issue_part);
		// Validate int 1-5
		if (validate_int(1, 5, issue_part))
			break;
		print_validation_err(issue_part);
	}

	while (1)
	{
		printf("\n診察希望日時(YYYYMMDD)\n例 : 2020年12月31日 -> 20201231\n");
		scanf("%d", &date);
		// Validate int today-1week
		if (validate_date(7, date))
			break;
		print_validation_err(date);
	}

	while (1)
	{
		printf("\n午前 : 1\n午後 : 2\n");
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

int	validate_date(int range_end, int input)
{
	time_t current_time = time(NULL);
	printf("%ld, %d, %d", current_time, range_end, input);
	if (current_time + 10080 <= )
	// 現在の日付を元にバリデーションを行う
	// 休館判定は未考慮
	return (0);
}

void	print_validation_err(int input)
{
	printf("\n%d は対象外の数値です。再度入力してください。\n", input);
}