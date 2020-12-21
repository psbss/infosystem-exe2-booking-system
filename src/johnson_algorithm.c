#include "mylib.h"

//ポインタで渡される(患者番号{0,1,2,～,10}、診察時間、施術時間、並び替え用の配列、合計時間保存用の変数)
void johnson(int* no, int* time1, int* time2,int* johnson, int* sumtime) {

	//最小時間
	int min_time;
	//最小時間の番号
	int min_costomer;
	//1から11人の患者（配列の先頭と末尾）
	int n, m;
	//M1とM2の合計時間
	int sumtime1, sumtime2;
	int i, change;

	//johnson配列にno配列の値をコピー
	for (i = 0; i < 11; i++) {
		johnson[i] = no[i];
	}

	//ジョンソン法
	n = 0;
	m = 10;
	while (m - n > 0) {

		min_time = 9999;
		min_costomer = 0;

		for (i = n ; i <= m; i++) {
			if (time1[johnson[i]] <= time2[johnson[i]]) {
				if (time1[johnson[i]] < min_time) {
					min_time = time1[johnson[i]];
					min_costomer = i + 1;
				}
				else if (time1[johnson[i]] == min_time) {
					if (min_costomer > 0 && time2[johnson[i]] > time2[johnson[abs(min_costomer) - 1]]) {
						min_time = time1[johnson[i]];
						min_costomer = i + 1;
					}
					if (min_costomer < 0) {
						min_time = time1[johnson[i]];
						min_costomer = i + 1;
					}
				}
			}
			else {
				if (time2[johnson[i]] < min_time) {
					min_time = time2[johnson[i]];
					min_costomer = -(i + 1);
				}
				else if (time2[johnson[i]] == min_time) {
					if (min_costomer < 0 && time1[johnson[i]] < time1[johnson[abs(min_costomer) - 1]]) {
						min_time = time2[johnson[i]];
						min_costomer = -(i + 1);
					}
				}
			}
		}
		if (min_costomer > 0) {
			change = johnson[n];
			johnson[n] = johnson[abs(min_costomer) - 1];
			johnson[abs(min_costomer) - 1] = change;
			n++;
		}
		else {
			change = johnson[m];
			johnson[m] = johnson[abs(min_costomer) - 1];
			johnson[abs(min_costomer) - 1] = change;
			m--;
		}
	}

	//合計時間（ガントチャート）
	sumtime1 = 0;
	for (i = 0; i < 11; i++) {
		sumtime1 += time1[johnson[i]];

		if (i == 0) {
			sumtime2 = sumtime1 + time2[johnson[i]];
		}
		//else if
		if (i > 0 && sumtime1 > sumtime2) {
			sumtime2 += time2[johnson[i]] + (sumtime1 - sumtime2);
		}
		//else
		if (i > 0 && sumtime1 <= sumtime2) {
			sumtime2 += time2[johnson[i]];
		}
	}
	*sumtime = sumtime2;

}
