#include "mylib.h"

// database : 
//  - 患者No
//  - issue_part
//  - date
//  - ampm
//  - 診察時間
//  - 施術時間
void test_inquiry(int no, int types, int db[][types]){
	int issue = 0;
	int date = get_time_now();
	int ampm = 1;
	for (int i = 0; i < no; i++)
	{
		if(issue == 0)
			date++;
		db[i][0] = i;
		db[i][1] = issue++;
		if(issue == 6)
			issue = 0;
		db[i][2] = date;
		db[i][3] = ampm++;
		if(ampm == 3)
			ampm = 1;
	}
}
