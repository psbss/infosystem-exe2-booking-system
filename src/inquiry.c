#include "mylib.h"

int inquiry(void){
	// int patient_no;
	int issue_part;
	int date;
	int ampm;

	// template
	// Must Validate
	printf("診察部位");
	scanf("%d", &issue_part);
	printf("診察希望日時");
	scanf("%d", &date);
	printf("午前・午後");
	scanf("%d", &ampm);

	printf("%d, %d, %d", issue_part, date, ampm);
	return (0);
}