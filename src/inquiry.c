#include "mylib.h"

int inquiry(void){
	// int patient_no;
	int issue_part;
	int date;
	int ampm;

	// template
	// Must Validate
	printf("診察部位\n\
					頭 : 1\n\
					手足 : 2\n\
					胸部, 腹部 : 3\n\
					予防接種 : 4\n\
					予約キャンセル : 5\n\
				");
	scanf("%d", &issue_part);
	// Validate int 1-5
	printf("診察希望日時(YYYYMMDD)\n\
					例 : 2020年12月31日 -> 20201231\n\
				");
	scanf("%d", &date);
	// Validate int today-1week

	printf("午前 : 1\n\
					午後 : 2\n\
				");
	scanf("%d", &ampm);
	// Validate int 1-2

	// printf("%d, %d, %d", issue_part, date, ampm);
	return (0);
}