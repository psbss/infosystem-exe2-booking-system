#include "mylib.h"

//ポインタで渡される(databaseの配列(0=患者番号、4=施術時間、5=診察時間)、ブロックの開始位置、ブロック内の人数、並び替え用の配列、合計時間保存用の変数)
void johnson(int database[][6], int start, int count, int* johnson, int* sumtime) {

	//最小時間
	int min_time;
	//最小時間の番号
	int min_costomer;
	//ブロック内の患者（先頭と末尾）
	int n, m;
	//M1とM2の合計時間
	int sumtime1, sumtime2;
	int i, change;

	//johnson配列にno配列の値をコピー
	for (i = 0; i < count; i++) {
		johnson[i] = database[start + i][0];
	}

	//ジョンソン法
	n = 0;
	m = count - 1;
	while (m - n >= 0) {

		min_time = 9999;
		min_costomer = 0;

		for (i = n; i <= m; i++) {
			if (database[johnson[i]][4] <= database[johnson[i]][5]) {
				if (database[johnson[i]][4] < min_time) {
					min_time = database[johnson[i]][4];
					min_costomer = i + 1;
				}
				else if (database[johnson[i]][4] == min_time) {
					if (min_costomer > 0 && database[johnson[i]][5] > database[johnson[abs(min_costomer) - 1]][5]) {
						min_time = database[johnson[i]][4];
						min_costomer = i + 1;
					}
					if (min_costomer < 0) {
						min_time = database[johnson[i]][4];
						min_costomer = i + 1;
					}
				}
			}
			else {
				if (database[johnson[i]][5] < min_time) {
					min_time = database[johnson[i]][5];
					min_costomer = -(i + 1);
				}
				else if (database[johnson[i]][5] == min_time) {
					if (min_costomer < 0 && database[johnson[i]][4] < database[johnson[abs(min_costomer) - 1]][4]) {
						min_time = database[johnson[i]][5];
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
	sumtime2 = 0;
	for (i = 0; i < count; i++) {
		sumtime1 += database[johnson[i]][4];

		if (i == start) {
			sumtime2 = sumtime1 + database[johnson[i]][5];
		}
		if (i > start && sumtime1 > sumtime2) {
			sumtime2 += database[johnson[i]][5] + (sumtime1 - sumtime2);
		}
		if (i > start && sumtime1 <= sumtime2) {
			sumtime2 += database[johnson[i]][5];
		}
	}
	*sumtime = sumtime2;

}
