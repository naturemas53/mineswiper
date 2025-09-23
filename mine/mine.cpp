// mineswiper.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <stdio.h>
#include <conio.h>

const int FIELD_X = 30;
const int FIELD_Y = 30;
const int BOMB_NUM = 100; //爆弾の数

bool countMarkNum(int refFieldArray[][FIELD_Y], const int fieldSize, const int bombX, const int bombY);

int _tmain(int argc, _TCHAR* argv[])
{
	int field[FIELD_X][FIELD_Y] = {};
	int setNum = BOMB_NUM;
	if (setNum >= FIELD_X * FIELD_Y)
	{
		printf("設定している爆弾の数が多すぎよ");
		setNum = (FIELD_X * FIELD_Y) - 1;
	}

	HANDLE h;
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	h = GetStdHandle(STD_OUTPUT_HANDLE); // 標準入出力へのハンドルを得る
	GetConsoleScreenBufferInfo(h, &csbi);// コンソールスクリーンバッファ（現在の状態）を得る

	srand((unsigned)time(NULL));

	//９は爆弾とする
	int x, y;
	for (int i = 0; i <= BOMB_NUM;) {

		x = rand() % FIELD_X;
		y = rand() % FIELD_Y;
		if (field[x][y] == 9) continue;
		if(!countMarkNum(field, FIELD_X*FIELD_Y, x, y)) continue;

		field[x][y] = 9;
		++i;
	}

	printf("爆弾の数は%dよ\n\n", BOMB_NUM);

	for (int i = 0; i < FIELD_X; i++) {
		for (int j = 0; j < FIELD_Y; j++) {

			if (field[i][j] == 9) {

				SetConsoleTextAttribute(h, FOREGROUND_RED); // 文字色を赤に変更
				//printf("%2d", field[i][j]);
				printf("＊");

			}
			else if (field[i][j] != 0) {

				SetConsoleTextAttribute(h, FOREGROUND_GREEN);
				printf("%2d", field[i][j]);

			}
			else {

				SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
				printf("%2d", field[i][j]);
			}


		}
		printf("\n");
	}


	printf("\n");
	return 0;
}

// ボムがある　周り　をカウントアップする（ヒント数増加）
// 整合性が取れない（ボムがフィールド外にある）とfalseを返します。
bool countMarkNum(int refFieldArray[][FIELD_Y], const int fieldSize, const int bombX, const int bombY)
{
	// 必要な変数を作りながら整合性チェック
	int bombIdx = FIELD_X * bombY + bombX;
	if (bombIdx < 0 || bombIdx >= fieldSize) return false;

	int markX = 0; int markY = 0; int markIdx = 0;
	for (int x = -1; x <= 1; ++x)
	{
		for (int y = -1; y <= 1; ++y)
		{
			markX = bombX + x;
			markY = bombY + y;
			bool isRangeOutX = (markX < 0) || (markX >= FIELD_X);
			bool isRangeOutY = (markY < 0) || (markY >= FIELD_Y);
			if (isRangeOutX || isRangeOutY) continue;

			/*
			markIdx = markY * FIELD_X + markX;
			if (refFieldArray[markIdx] == 9) continue;

			refFieldArray[markIdx]++;
			*/
			if (refFieldArray[markX][markY] == 9) continue;

			refFieldArray[markX][markY]++;
		}
	}

	return true;

}