/* 2351883 信06 陈奕名 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <tchar.h>
#include <string.h>
#include <Windows.h>
#include <conio.h>
#include "cmd_console_tools.h"
#include "magic_ball.h"
using namespace std;
void det_enter() 
{
	while (1) {
		int n = _getch();
		if (n == 13) {
			break;
		}
	}
}

void det_end(int x, int y) 
{
	while (1) {
		cct_gotoxy(x, y);
		cout << "本小题结束，请输入End继续...";
		char n[10] = {0};
		int i = 0;
		while (i < 10)
		{
			n[i] = getchar();
			if (n[i] == '\n')
				break;
			i++;
		}
		if (strlen(n) == 4) {
			if ((n[0] == 'E' || n[0] == 'e') && (n[1] == 'N' || n[1] == 'n') && (n[2] == 'D' || n[2] == 'd')) {
				break;
			}
		}
		cct_gotoxy(x, y);
		cout << "本小题结束，请输入End继续...           "<<endl ;
		cout << "输入错误，请重新输入";
	}
}