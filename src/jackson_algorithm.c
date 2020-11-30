#include "mylib.h"

int jackson()
{

}

#include "mylib.h"

struct BODY
{
	int time1; //M1
	int time2; //M2
};

struct COSTOMER
{
	int no; //患部
};


int main(void) {

	struct BODY body[4];
	struct COSTOMER costomer[11], johnson[11],change; //chageはjohnsonの値を保存
	
	int min_time; //最小時間
	int min_costomer;//最小時間の番号
	int n, m; //1から11人の患者（配列の先頭と末尾）
	int sumtime1, sumtime2; //M1とM2の合計時間
	int i;

	//bodyの初期値代入

	//costomerの初期値代入

    //costomerのデータをjohnsonへ移す

	//ジョンソン法
	n = 0;
	m = 10;
	while (m - n > 0){

		min_time = body[johnson[n].no].time1;
		min_costomer = n + 1;

		for (i = n; i <= m; i++) {
			if (body[johnson[i].no].time1 <= body[johnson[i].no].time2) {
				if ((body[johnson[i].no].time1 == min_time && body[johnson[i].no].time2 < body[johnson[abs(min_costomer) - 1].no].time2) || body[johnson[i].no].time1 < min_time) {
					min_time = body[johnson[i].no].time1;
					min_costomer = i + 1;
				}
			}
			//else
			if (body[johnson[i].no].time1 > body[johnson[i].no].time2) {
				if ((body[johnson[i].no].time1 == min_time && body[johnson[i].no].time1 > body[johnson[abs(min_costomer) - 1].no].time1) || body[johnson[i].no].time2 < min_time) {
					min_time = body[johnson[i].no].time2;
					min_costomer = -(i + 1);
				}
			}
		}
		if (min_time > 0) {
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
		sumtime1 += body[johnson[i].no].time1;

		if (i == 0) {
			sumtime2 = sumtime1 + body[johnson[i].no].time2;
		}
		//else if
		if (i > 0 && sumtime1 > sumtime2) {
			sumtime2 += body[johnson[i].no].time2 + (sumtime1 - sumtime2);
		}
		//else
		if (i > 0 && sumtime1 <= sumtime2) {
			sumtime2 += body[johnson[i].no].time2;
		}
	}

	return 0;
}
