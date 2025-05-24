/* 2351883 信06 陈奕名 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <tchar.h>
#include <string.h>
#include <Windows.h>
#include <conio.h>
#include "cmd_console_tools.h"
#include "hanoi.h"
using namespace std;

int sum = 0;
int a[3][10];
int b[3];
/* ----------------------------------------------------------------------------------

	 本文件功能：
	1、存放被 hanoi_main.cpp 中根据菜单返回值调用的各菜单项对应的执行函数

	 本文件要求：
	1、不允许定义外部全局变量（const及#define不在限制范围内）
	2、允许定义静态全局变量（具体需要的数量不要超过文档显示，全局变量的使用准则是：少用、慎用、能不用尽量不用）
	3、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
	4、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------------------------------------------------- */


void con() {
	sum = 0;
	for (int i = 0; i < 3; i++) {
		b[i] = 0;
		for (int j = 0; j < 10; j++) {
			a[i][j] = 0;
		}
	}
	char t;
	cout << "按回车键继续";
	while (1) {
		t = _getch();
		if (t == 13)
			break;
	}
	cct_cls();
}

void p(int n, char src, char tmp, char dst, int mode, int speed) {
	if (mode == 1) {
		cout << n << "# " << src << "---->" << dst << endl;
	}
	if (mode == 2) {
		cout << setfill(' ') << "第" << setw(4) << sum << "步" << "(" << setw(2) << n << "#: " << src << "-->" << dst << ")" << endl;
	}
	if (mode == 3) {
		move(src, dst);
		cout << setfill(' ') << "第" << setw(4) << sum << "步" << "(" << setw(2) << n << "#: " << src << "-->" << dst << ")" << "  ";
		sc(src, tmp, dst);
	}
	if (mode == 4) {
		move(src, dst);
		yidong(mode);
		cct_gotoxy(0, 17);
		cout << setfill(' ') << "第" << setw(4) << sum << "步" << "(" << setw(2) << n << "#: " << src << "-->" << dst << ")" << "  ";
		sc(src, tmp, dst);
		delay(speed);
	}
	if (mode == 5) {
		cct_cls();
		zhu();
	}
	if (mode == 6) {
		cct_cls();
		zhu();
		pan(n);
	}
	if (mode == 7) {
		cct_cls();
		zhu();
		pan(n);
		Sleep(2000);
		movep(n, src, tmp, dst, mode, speed);
	}
	if (mode == 8 || mode == 9) {
		movep(n, src, tmp, dst, mode, speed);
	}

}

void zhu()
{
	for (int i = 1; i < 80; i += 32) {
		cct_gotoxy(i, 15);
		cct_showch(i, 15, ' ', COLOR_HYELLOW, COLOR_CYAN, 23);
		Sleep(50);
	}
	for (int j = 1; j <= 11; j++) {
		for (int i = 12; i < 80; i += 32) {
			cct_gotoxy(i, 15 - j);
			cct_showch(i, 15 - j, ' ', COLOR_HYELLOW, COLOR_CYAN, 1);
			Sleep(50);
		}
	}
	cct_setcolor();
}

void pan(int n)
{
	int k = 0;
	for (int k = 0; k < 3; k++) {
		for (int i = 0; i < b[k]; i++) {
			cct_gotoxy(12 + 32 * k - a[k][i], 14 - i);
			cct_showch(12 + 32 * k - a[k][i], 14 - i, ' ', b[k] - i, COLOR_CYAN, 1 + 2 * a[k][i]);
			Sleep(50);
		}
	}
	cct_setcolor();
}

void move(char src, char dst)
{
	a[dst - 'A'][b[dst - 'A']++] = a[src - 'A'][--b[src - 'A']];
}


void movep(int n, char src, char tmp, char dst, int mode, int speed) {
	int s = src - 'A', d = dst - 'A';
	int sp = b[src - 'A'], dp = b[dst - 'A'];
	int pa = a[src - 'A'][b[src - 'A'] - 1];
	move(src, dst);
	if (mode == 8 || mode == 9) {
		delay(speed);
		yidong(mode);
		cct_gotoxy(0, 33);
		cout << setfill(' ') << "第" << setw(4) << sum << "步" << "(" << setw(2) << n << "#: " << src << "-->" << dst << ")" << "  ";
		sc(src, tmp, dst);
	}
	for (int i = 14 - sp; i > 0; i--) {
		cct_gotoxy(12 + 32 * s - pa, i + 1);
		cct_showch(12 + 32 * s - pa, i + 1, ' ', COLOR_BLACK, COLOR_WHITE, 1 + 2 * pa);
		if (i > 2) {
			cct_gotoxy(12 + 32 * s, i + 1);
			cct_showch(12 + 32 * s, i + 1, ' ', COLOR_HYELLOW, COLOR_CYAN, 1);
		}
		cct_gotoxy(12 + 32 * s - pa, i);
		cct_showch(12 + 32 * s - pa, i, ' ', pa, COLOR_CYAN, 1 + 2 * pa);
		if (speed == 0)
			Sleep(100);
		else {
			delay(speed);
		}
	}
	if (dst > src) {
		for (int i = 12 + 32 * s - pa; i < 12 + 32 * s - pa + 32 * (d - s); i++) {
			cct_gotoxy(i, 1);
			cct_showch(i, 1, ' ', COLOR_BLACK, COLOR_WHITE, 1 + 2 * pa);
			cct_gotoxy(i + 1, 1);
			cct_showch(i + 1, 1, ' ', pa, COLOR_CYAN, 1 + 2 * pa);
			if (speed == 0)
				Sleep(100);
			else {
				delay(speed);
			}
		}
	}
	else {
		for (int i = 12 + 32 * s - pa; i > 12 + 32 * s - pa + 32 * (d - s); i--) {
			cct_gotoxy(i, 1);
			cct_showch(i, 1, ' ', COLOR_BLACK, COLOR_WHITE, 1 + 2 * pa);
			cct_gotoxy(i - 1, 1);
			cct_showch(i - 1, 1, ' ', pa, COLOR_CYAN, 1 + 2 * pa);
			if (speed == 0)
				Sleep(100);
			else {
				delay(speed);
			}
		}
	}
	for (int i = 2; i <= 14 - dp; i++) {
		cct_gotoxy(12 + 32 * d - pa, i - 1);
		cct_showch(12 + 32 * d - pa, i - 1, ' ', COLOR_BLACK, COLOR_WHITE, 1 + 2 * pa);
		if (i > 4) {
			cct_gotoxy(12 + 32 * d, i - 1);
			cct_showch(12 + 32 * d, i - 1, ' ', COLOR_HYELLOW, COLOR_CYAN, 1);
		}
		cct_gotoxy(12 + 32 * d - pa, i);
		cct_showch(12 + 32 * d - pa, i, ' ', pa, COLOR_CYAN, 1 + 2 * pa);
		if (speed == 0)
			Sleep(100);
		else {
			delay(speed);
		}
	}
	cct_setcolor();
}


void open(int n, char s) {
	for (int i = n; i >= 1; i--) {
		a[s - 'A'][n - i] = i;
	}
	b[s - 'A'] = n;
}

void delay(int speed) {
	if (speed == 0) {
		char c;
		while (1) {
			c = _getch();
			if (c == 13)
				break;
		}
	}
	else {
		Sleep(250 - 50 * speed);
	}
}

void sc(char src, char tmp, char dst)
{
	char h[3] = { src,tmp,dst };
	cout << "A:";
	for (int i = 0; i < 3; i++) {
		if (h[i] == 'A') {
			for (int j = 0; j < b[h[i] - 'A']; j++) {
				cout << setw(2) << a[h[i] - 'A'][j];
			}
			for (int j = b[h[i] - 'A']; j < 10; j++) {
				cout << "  ";
			}
		}
	}
	cout << " ";
	cout << "B:";
	for (int i = 0; i < 3; i++) {
		if (h[i] == 'B') {
			for (int j = 0; j < b[h[i] - 'A']; j++) {
				cout << setw(2) << a[h[i] - 'A'][j];
			}
			for (int j = b[h[i] - 'A']; j < 10; j++) {
				cout << "  ";
			}
		}
	}
	cout << " ";
	cout << "C:";
	for (int i = 0; i < 3; i++) {
		if (h[i] == 'C') {
			for (int j = 0; j < b[h[i] - 'A']; j++) {
				cout << setw(2) << a[h[i] - 'A'][j];
			}
			for (int j = b[h[i] - 'A']; j < 10; j++) {
				cout << "  ";
			}
		}
	}
	cout << endl;
}

void yidong(int mode)
{
	int o = (mode / 8) * 16;
	for (int i = 0; i < b[0]; i++) {
		cct_gotoxy(ZHU_A, 11 + o - i);
		cout << setfill(' ') << setw(2) << a[0][i];
	}
	for (int i = b[0]; i < 10; i++) {
		cct_gotoxy(ZHU_A, 11 + o - i);
		cout << setfill(' ') << setw(2) << " ";
	}
	for (int i = 0; i < b[1]; i++) {
		cct_gotoxy(ZHU_B, 11 + o - i);
		cout << setfill(' ') << setw(2) << a[1][i];
	}
	for (int i = b[1]; i < 10; i++) {
		cct_gotoxy(ZHU_B, 11 + o - i);
		cout << setfill(' ') << setw(2) << " ";
	}
	for (int i = 0; i < b[2]; i++) {
		cct_gotoxy(ZHU_C, 11 + o - i);
		cout << setfill(' ') << setw(2) << a[2][i];
	}
	for (int i = b[2]; i < 10; i++) {
		cct_gotoxy(ZHU_C, 11 + o - i);
		cout << setfill(' ') << setw(2) << " ";
	}

}
void ssc(char s, char t, char d, int n, int speed, int mode)
{
	int o = (mode / 8) * 16;
	cct_cls();
	if (mode != 9)
		cout << "从 " << s << " 移动到 " << d << "，共 " << n << " 层，延时设置为 " << speed << endl;
	else
		cout << "从 " << s << " 移动到 " << d << "，共 " << n << " 层" << endl;
	cct_gotoxy(9, 12 + o);
	cout << setfill('=') << setw(25) << "=";
	cct_gotoxy(11, 13 + o);
	cout << "A";
	cct_gotoxy(21, 13 + o);
	cout << "B";
	cct_gotoxy(31, 13 + o);
	cout << "C";
	yidong(mode);
	cct_gotoxy(0, 17 + o);
	cout << "初始:  ";
	sc(s, t, d);
	if (mode != 8)
		delay(speed);
}



void hanoi(int n, char src, char tmp, char dst, int mode, int speed)
{
	if (n == 1) {
		sum++;
		p(n, src, tmp, dst, mode, speed);
		return;
	}
	hanoi(n - 1, src, dst, tmp, mode, speed);
	sum++;
	p(n, src, tmp, dst, mode, speed);
	hanoi(n - 1, tmp, src, dst, mode, speed);
}

void hanoir(int n, char src, char tmp, char dst, int mode, int speed)
{
	if (mode < 4)
		hanoi(n, src, tmp, dst, mode, speed);

	if (mode == 4) {
		cct_setcursor(CURSOR_INVISIBLE);
		ssc(src, tmp, dst, n, speed, mode);
		hanoi(n, src, tmp, dst, mode, speed);
		cct_setcursor(CURSOR_VISIBLE_NORMAL);
	}

	if (mode > 4 && mode < 8) {
		p(n, src, tmp, dst, mode, speed);
	}

	if (mode == 8) {
		ssc(src, tmp, dst, n, speed, mode);
		zhu();
		pan(n);
		hanoi(n, src, tmp, dst, mode, speed);
	}
	if (mode == 9) {
		handmove(n, src, tmp, dst, mode, speed);
	}
}

void handmove(int n, char src, char tmp, char dst, int mode, int speed) {
	ssc(src, tmp, dst, n, 3, mode);
	zhu();
	pan(n);
	int flag = 1;
	while (1) {
		char s = 0, t = 0, d = 0;
		while (1) {
			char f[10];
			cct_gotoxy(0, 35);
			cout << "                                                                                                         ";
			cct_gotoxy(0, 35);
			cout << "请输入移动的柱号(命令形式：AC=A顶端的盘子移动到C，Q=退出) ：";
			for (int i = 0; i < 10; i++) {
				f[i] = _getch();
				if (f[i] == 13)
					break;
				else
					cout << f[i];
			}

			if ((f[0] == 'q' || f[0] == 'Q') && f[1] == 13) {
				cout << endl;
				cout << "游戏终止!!!!!" << endl;
				flag = 0;
				break;
			}

			if (f[2] != 13 || f[0] == 13 || f[1] == 0)
				continue;

			if (f[0] >= 'a' && f[0] <= 'c') {
				f[0] = f[0] - 'a' + 'A';
			}

			if (f[1] >= 'a' && f[1] <= 'c') {
				f[1] = f[1] - 'a' + 'A';
			}

			if (f[1] < 'A' || f[1]>'C' || f[0] < 'A' || f[0]>'C')
				continue;

			if (f[1] == f[0]) {
				continue;
			}

			if (b[f[0] - 'A'] < 1) {
				cout << endl;
				cout << "源柱为空!";
				Sleep(1000);
				cct_gotoxy(0, 36);
				cout << "         ";
				continue;
			}

			if (b[f[1] - 'A'] > 0) {
				if (a[f[0] - 'A'][b[f[0] - 'A'] - 1] > a[f[1] - 'A'][b[f[1] - 'A'] - 1]) {
					cout << endl;
					cout << "大盘压小盘，非法移动!";
					Sleep(1000);
					cct_gotoxy(0, 36);
					cout << "                     ";
					continue;
				}
			}
			s = f[0], d = f[1], t = 'A' + 'B' + 'C' - s - d;
			break;
		}
		if (flag == 0)
			break;
		sum++;
		p(a[s - 'A'][b[s - 'A'] - 1], s, t, d, mode, 4);
		if (b[dst - 'A'] == n) {
			cct_gotoxy(0, 36);
			cout << "游戏结束!!!!!" << endl;
			break;
		}

	}
}