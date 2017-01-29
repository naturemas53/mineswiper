// mineswiper.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
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
	int bombnum = 100; //���e�̐�
	int x, y;

	HANDLE h;
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	h = GetStdHandle(STD_OUTPUT_HANDLE); // �W�����o�͂ւ̃n���h���𓾂�
	GetConsoleScreenBufferInfo(h, &csbi); // �R���\�[���X�N���[���o�b�t�@�i���݂̏�ԁj�𓾂�

	srand((unsigned)time(NULL));
	//�X�͔��e�Ƃ���
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

	printf("���e�̐���%d��\n\n", bombnum);

	for (int i = 0; i<30; i++){
		for (int j = 0; j<30; j++){

			if (field[i][j] == 9){

				SetConsoleTextAttribute(h, FOREGROUND_RED); // �����F��ԂɕύX
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

/*�т�т�т�т�т�т�т�т�т�т�т�т�т�т�т�т�т�т�
������
����������������������������������������������������
����
33-4

�X�Y���o�`�ɂ͋C��t���悤�I*/
