// mineswiper.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <stdio.h>
#include <conio.h>


int _tmain(int argc, _TCHAR* argv[])
{
	int field[30][30] = {};
	int bombnum = 100; //爆弾の数
	int x, y;

	HANDLE h;
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	h = GetStdHandle(STD_OUTPUT_HANDLE); // 標準入出力へのハンドルを得る
	GetConsoleScreenBufferInfo(h, &csbi); // コンソールスクリーンバッファ（現在の状態）を得る

	srand((unsigned)time(NULL));
	//９は爆弾とする
	for (int i = 0; i <= bombnum;){

		x = rand() % 30;
		y = rand() % 30;
		if (field[x][y] != 9){
			field[x][y] = 9;
			i++;
		}
	}

	for (int i = 0; i<30; i++){
		for (int j = 0; j<30; j++){

			if (field[i][j] != 9){
				for (int chx = 1; chx >= -1; chx--){
					for (int chy = -1; chy <= 1; chy++){
						if ((i + chx >= 0 && i + chx <= 29) && (j + chy >= 0 && j + chy <= 29)){
							if (field[i + chx][j + chy] == 9){

								field[i][j] = field[i][j] + 1;

							}
						}
					}
				}
			}

		}
	}

	printf("爆弾の数は%dよ\n\n", bombnum);

	for (int i = 0; i<30; i++){
		for (int j = 0; j<30; j++){

			if (field[i][j] == 9){

				SetConsoleTextAttribute(h, FOREGROUND_RED); // 文字色を赤に変更
				printf("%2d", field[i][j]);

			}
			else if (field[i][j] != 0){

				SetConsoleTextAttribute(h, FOREGROUND_GREEN);
				printf("%2d", field[i][j]);

			}
			else{

				SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
				printf("%2d", field[i][j]);
			}


		}
		printf("\n");
	}


	printf("\n");
	return 0;
}

/*びんびんびんびんびんびんびんびんびんびんびんびんびんびんびんびんびんびん
ちくっ
ああああああああああああああああああああああああああ
ｱｰｲｸ
33-4

スズメバチには気を付けよう！*/
