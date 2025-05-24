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
void graph(int mode, int h, int l, int map[][11], int map_flag[][11], int map_change[][11])
{
	cct_setcursor(CURSOR_INVISIBLE);
	if (mode == 4 || mode == 5) {
		cout << "初始数组:" << endl;
		fill(h, l, map);
		print_map(mode, h, l, map, map_flag);
		det_enter();
		cout << endl;
		print_ball(mode, h, l, map, map_flag, map_change);
		int x, y;
		cct_getxy(x, y);
		det_end(x, y);
	}
	if (mode == 6) {
		fill(h, l, map);
		cout << endl;
		print_ball(mode, h, l, map, map_flag, map_change);
		int p = g_mark(mode, h, l, map, map_flag);
		if (p == 0) {
			cct_gotoxy(0, 0);
			cout << "屏幕：" << 6 + h << "行" << 40 << "列" << "(未找到初始可消除项)" ;
		}
		det_end(0, h + 3);
	}
	if (mode == 7 || mode == 8) {
		fill(h, l, map);
		cout << endl;
		print_ball(mode, h, l, map, map_flag, map_change);
		while (1) {
			for (int i = 1; i <= h; i++) {
				for (int j = 1; j <= l; j++) {
					map_flag[i][j] = 0;
				}
			}
			int p = g_mark(mode, h, l, map, map_flag);
			if (p == 0) {
				cct_gotoxy(0, 0);
				cout << "屏幕：" << 5 + 2 * h << "行" << 40 << "列" << "(未找到初始可消除项)" ;
				break;
			}
			cct_gotoxy(0, 2 * h + 2);
			cout << "按回车键进行消除及下落除0操作...";
			det_enter();
			g_clear(mode, h, l, map, map_flag);
			g_fall(mode, h, l, map, map_flag, map_change);
			cct_gotoxy(0, 2 * h + 2);
			cout << "按回车键进行新值填充...         ";
			det_enter();
			g_fill(mode, h, l, map, map_flag, map_change);
		}
		cct_gotoxy(0, 2 * h + 2);
		cout << "按回车键显示消除提示...         ";
		det_enter();
		g_se(mode, h, l, map, map_flag, map_change);
		if (mode == 8) {
			cct_gotoxy(0, 0);
			cout << "屏幕：" << 5 + 2 * h << "行" << 40 << "列" << "(当前分数 0 右键退出)     " ;
			cct_enable_mouse();
			int X, Y, maction, keycode1, keycode2;
			while (1) {
				cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);
				cct_gotoxy(0, 2 * h + 2);
				int flag = 0;
				if (Y % 2 == 0 && Y <= 2 * h) {
					if (((X + 1) % 4 == 0 || (X + 2) % 4 == 0) && X <= 4 * l - 1) {
						cout << "[当前光标] " << char('A' + Y / 2 - 1) << "行" << (X + 2) / 4 << "列      ";
						flag = 1;
					}
				}
				if (!flag)
					cout << "[当前光标] 位置非法     ";
				if (maction == MOUSE_RIGHT_BUTTON_CLICK)
					break;
			}
		}
		det_end(0, 2 * h + 2);
	}

	if (mode == 9) {
		fill(h, l, map);
		cout << endl;
		print_ball(mode, h, l, map, map_flag, map_change);
		cct_gotoxy(0, 0);
		cout << "屏幕：" << 5 + 2 * h << "行" << 40 << "列" << "(当前分数 0 )" ;
		while (1) {
			for (int i = 1; i <= h; i++) {
				for (int j = 1; j <= l; j++) {
					map_flag[i][j] = 0;
				}
			}

			int p = g_mark(mode, h, l, map, map_flag);
			if (p == 0) {
				break;
			}
			g_clear(mode, h, l, map, map_flag);
			g_fall(mode, h, l, map, map_flag, map_change);
			g_fill(mode, h, l, map, map_flag, map_change);
		}
		g_se(mode, h, l, map, map_flag, map_change);
		cct_enable_mouse();
		int X, Y, maction, keycode1, keycode2;
		int num = 0;
		int f = 0, fx = 10000, fy = 10000;
		while (1) {
			cct_gotoxy(0, 0);
			cout << "屏幕：" << 5 + 2 * h << "行" << 40 << "列" << "(当前分数 " << num << " 右键退出)    ";
			f = 0, fx = 10000, fy = 10000;
			if (g_sea(mode, h, l, map, map_flag, map_change) == 0) {
				cct_gotoxy(0, 0);
				cout << "无可消除项，游戏结束！最终分数：" << num << ")  ";
				break;
			}
			while (1) {
				cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);
				cct_gotoxy(0, 2 * h + 2);
				int flag = 0;
				if (Y % 2 == 0 && Y <= 2 * h && Y >= 2) {
					if (((X + 1) % 4 == 0 || (X + 2) % 4 == 0) && X <= 4 * l - 1) {
						cout << "[当前光标] " << char('A' + Y / 2 - 1) << "行" << (X + 2) / 4 << "列         ";
						flag = 1;
					}
				}
				if (!flag)
					cout << "[当前光标] 位置非法";
				if (maction == MOUSE_LEFT_BUTTON_CLICK) {
					if (flag == 1) {
						if (map_change[Y / 2][(X + 2) / 4] == 1) {
							cct_gotoxy(0, 2 * h + 2);
							cout << "当前选择" << char('A' + Y / 2 - 1) << "行" << (X + 2) / 4 << "列         ";
							Sleep(10);
							if (f == 0) {
								cct_showstr(((X + 2) / 4) * 4 - 2, 2 * (Y / 2), "◎", map[Y / 2][(X + 2) / 4], COLOR_HWHITE);
								cct_setcolor();
								fx = ((X + 2) / 4) * 4 - 2;
								fy = 2 * (Y / 2);
								f = 1;
							}
							else if (f == 1) {
								if (fx == ((X + 2) / 4) * 4 - 2 && fy == 2 * (Y / 2)) {
									cct_showstr(((X + 2) / 4) * 4 - 2, 2 * (Y / 2), "◎", map[Y / 2][(X + 2) / 4], COLOR_BLACK);
									cct_setcolor();
									fx = 10000;
									fy = 10000;
									f = 0;
								}
								else if ((((X + 2) / 4) * 4 - 2 == fx - 4 && fy == 2 * (Y / 2)) || (((X + 2) / 4) * 4 - 2 == fx + 4 && fy == 2 * (Y / 2)) || 
									(((X + 2) / 4) * 4 - 2 == fx && fy - 2 == 2 * (Y / 2)) || (((X + 2) / 4) * 4 - 2 == fx && fy + 2 == 2 * (Y / 2)))
								{
									//num += sum(mode, h, l, map, map_flag);
									int t1 = map[Y / 2][(X + 2) / 4];
									int t2 = map[fy / 2][(fx + 2) / 4];
									map[Y / 2][(X + 2) / 4] = t2;
									map[fy / 2][(fx + 2) / 4] = t1;
									mark(h, l, map, map_flag);
									if (sum(mode, h, l, map, map_flag) == 0) {
										cct_gotoxy(0, 2 * h + 2);
										cout << "不能交换" << char('A' + fy / 2 - 1) << "行" << (fx + 2) / 4 << "列 <=> " << char('A' + Y / 2 - 1) << "行" << (X + 2) / 4 << "列";
										Sleep(50);
										map[Y / 2][(X + 2) / 4] = t1;
										map[fy / 2][(fx + 2) / 4] = t2;
										mark(h, l, map, map_flag);
										cct_showstr(fx, fy, "◎", map[fy / 2][(fx + 2) / 4], COLOR_BLACK);
										cct_setcolor();
										fx = 10000;
										fy = 10000;
										f = 0;
									}
									else {
										break;
									}
								}
								else {
									cct_showstr(fx, fy, "◎", map[fy / 2][(fx + 2) / 4], COLOR_BLACK);
									cct_showstr(((X + 2) / 4) * 4 - 2, 2 * (Y / 2), "◎", map[Y / 2][(X + 2) / 4], COLOR_HWHITE);
									cct_setcolor();
									fx = ((X + 2) / 4) * 4 - 2;
									fy = 2 * (Y / 2);
									f = 1;
								}
							}
						}
						else {
							cct_gotoxy(0, 2 * h + 2);
							cout << "不能选择" << char('A' + Y / 2 - 1) << "行" << (X + 2) / 4 << "列        ";
							Sleep(100);
						}
					}
				}
				if (maction == MOUSE_RIGHT_BUTTON_CLICK) {
					det_end(0, 2 * h + 2);
					return;
				}
			}
			p_ball(mode, h, l, map, map_flag, map_change);
			while (1) {
				for (int i = 1; i <= h; i++) {
					for (int j = 1; j <= l; j++) {
						map_flag[i][j] = 0;
					}
				}
				for (int i = 1; i <= h; i++) {
					for (int j = 1; j <= l; j++) {
						map_change[i][j] = 0;
					}
				}
				int p = g_mark(mode, h, l, map, map_flag);
				if (p == 0) {
					break;
				}
				g_clear(mode, h, l, map, map_flag);
				g_fall(mode, h, l, map, map_flag, map_change);
				g_fill(mode, h, l, map, map_flag, map_change);
				num += sum(mode, h, l, map, map_flag);
			}
			g_se(mode, h, l, map, map_flag, map_change);
			if (g_sea(mode, h, l, map, map_flag, map_change) == 0) {
				cct_gotoxy(0, 0);
				cout << "无可消除项，游戏结束！最终分数：" << num << ")  ";
				break;
			}
		}
		det_end(0, 2 * h + 2);
	}

}

void print_ball(int mode, int h, int l, int map[][11], int map_flag[][11], int map_change[][11])
{
	if (mode == 4 || mode == 6) {
		cct_cls();
		cct_setfontsize("新宋体", 36);
		cct_setconsoleborder(40, 6 + h, 40, 16 + h);
		cout << "屏幕：" << 6 + h << "行" << 40 << "列" << endl;
		cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
		for (int k = 0; k <= l + 1; k++) {
			if (k == 0) {
				cout << "╔";
			}
			else if (k == l + 1) {
				cout << "╗";
			}
			else {
				cout << "═";
			}
		}
		cout << endl;


		for (int i = 1; i <= h; i++) {
			cct_showstr(0, i + 1, "║", COLOR_HWHITE, COLOR_BLACK);
			Sleep(10);
			cct_setcolor();
		}


		for (int i = 1; i <= h; i++) {
			cct_showstr(2 * (l + 1), i + 1, "║", COLOR_HWHITE, COLOR_BLACK);
			Sleep(10);
		}
		cct_gotoxy(0, h + 2);
		for (int k = 0; k <= l + 1; k++) {
			if (k == 0) {
				cout << "╚";
				Sleep(10);
			}
			else if (k == l + 1) {
				cout << "╝";
				Sleep(10);
			}
			else {
				cout << "═";
				Sleep(10);
			}
		}

		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= l; j++) {
				cct_showstr(j * 2, i + 1, "〇", map[i][j], COLOR_BLACK);
				Sleep(10);
				cct_setcolor();
			}
			cout << endl;
		}

		cct_setcolor();
		cout << endl;
	}
	if (mode == 5 || mode == 7 || mode == 8 || mode == 9) {
		cct_cls();
		cct_setfontsize("新宋体", 36);
		cct_setconsoleborder(40, 5 + 2 * h, 40, 15 + 2 * h);
		cout << "屏幕：" << 5 + 2 * h << "行" << 40 << "列" << endl;
		cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
		for (int k = 0; k <= 2 * l; k++) {
			if (k == 0) {
				cout << "╔";
			}
			else if (k == 2 * l) {
				cout << "╗";
			}
			else if (k % 2 == 0) {
				cout << "╦";
			}
			else {
				cout << "═";
			}
		}
		cout << endl;

		for (int i = 1; i <= 2 * h - 1; i++) {
			for (int j = 1; j <= 2 * l + 1; j++) {
				if (i % 2 == 0) {
					if (j == 1) {
						cout << "╠";
					}
					else if (j == 2 * l + 1) {
						cout << "╣";
					}
					else if (j % 2 == 0) {
						cout << "═";
					}
					else {
						cout << "╬";
					}
				}
				else {
					if (j % 2 == 0) {
						cout << "  ";
					}
					else {
						cout << "║";
					}
				}
			}
			cout << endl;
		}

		for (int k = 0; k <= 2 * l; k++) {
			if (k == 0) {
				cout << "╚";
			}
			else if (k == 2 * l) {
				cout << "╝";
			}
			else if (k % 2 == 0) {
				cout << "╩";
			}
			else {
				cout << "═";
			}
		}
		cout << endl;

		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= l; j++) {
				if (map[i][j])
					cct_showstr(j * 4 - 2, 2 * i, "〇", map[i][j], COLOR_BLACK);
				else
					cct_showstr(j * 4 - 2, 2 * i, "  ", COLOR_HWHITE, COLOR_BLACK);
				Sleep(10);
				cct_setcolor();
			}
			cout << endl;
		}

		cct_setcolor();
		cout << endl;
	}
}

void p_ball(int mode, int h, int l, int map[][11], int map_flag[][11], int map_change[][11])
{
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= l; j++) {
			if (map[i][j])
				cct_showstr(j * 4 - 2, 2 * i, "〇", map[i][j], COLOR_BLACK);
		}
	}
	cct_setcolor();
}

void print_ball_nt(int mode, int h, int l, int map[][11], int map_flag[][11], int map_change[][11])
{
	cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
	cct_gotoxy(0, 1);
	for (int k = 0; k <= 2 * l; k++) {
		if (k == 0) {
			cout << "╔";
		}
		else if (k == 2 * l) {
			cout << "╗";
		}
		else if (k % 2 == 0) {
			cout << "╦";
		}
		else {
			cout << "═";
		}
	}
	cout << endl;

	for (int i = 1; i <= 2 * h - 1; i++) {
		for (int j = 1; j <= 2 * l + 1; j++) {
			if (i % 2 == 0) {
				if (j == 1) {
					cout << "╠";
				}
				else if (j == 2 * l + 1) {
					cout << "╣";
				}
				else if (j % 2 == 0) {
					cout << "═";
				}
				else {
					cout << "╬";
				}
			}
			else {
				if (j % 2 == 0) {
					cout << "  ";
				}
				else {
					cout << "║";
				}
			}
		}
		cout << endl;
	}

	for (int k = 0; k <= 2 * l; k++) {
		if (k == 0) {
			cout << "╚";
		}
		else if (k == 2 * l) {
			cout << "╝";
		}
		else if (k % 2 == 0) {
			cout << "╩";
		}
		else {
			cout << "═";
		}
	}
	cout << endl;

	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= l; j++) {
			if (map[i][j])
				cct_showstr(j * 4 - 2, 2 * i, "〇", map[i][j], COLOR_BLACK);
			else
				cct_showstr(j * 4 - 2, 2 * i, "  ", COLOR_HWHITE, COLOR_BLACK);
			cct_setcolor();
		}
		cout << endl;
	}
	cct_setcolor();
	cout << endl;
}


int g_mark(int mode, int h, int l, int map[][11], int map_flag[][11]) {
	int p = mark(h, l, map, map_flag);
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= l; j++) {
			if (map_flag[i][j]) {
				if (mode == 6)
					cct_showstr(j * 2, i + 1, "●", map[i][j], COLOR_BLACK);
				if (mode == 7 || mode == 8 || mode == 9)
					cct_showstr(j * 4 - 2, 2 * i, "●", map[i][j], COLOR_BLACK);
				Sleep(10);
			}
			cct_setcolor();
		}
	}
	return p;
}

int sum(int mode, int h, int l, int map[][11], int map_flag[][11]) 
{
	int a = 0;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= l; j++) {
			if (map_flag[i][j]) {
				a++;
			}
		}
	}
	return a;
}

void g_clear(int mode, int h, int l, int map[][11], int map_flag[][11]) 
{
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= l; j++) {
			if (map_flag[i][j]) {
				for (int k = 1; k <= 5; k++) {
					cct_showstr(j * 4 - 2, 2 * i, "¤", map[i][j], COLOR_BLACK);
					Sleep(50);
					cct_showstr(j * 4 - 2, 2 * i, "〇", map[i][j], COLOR_BLACK);
					Sleep(50);
				}
				map[i][j] = 0;
				cct_showstr(j * 4 - 2, 2 * i, "  ", COLOR_HWHITE, COLOR_HWHITE);
			}
			Sleep(10);
			cct_setcolor();
		}
	}
}

void g_fall(int mode, int h, int l, int map[][11], int map_flag[][11], int map_change[][11]) 
{
	for (int i = 1; i <= l; i++) {
		for (int j = h; j >= 1; j--) {
			if (map[j][i] == 0) {
				for (int k = j; k >= 1; k--) {
					if (map[k][i] != 0) {
						int t = k;
						int z = map[k][i];
						map[k][i] = 0;
						map[j][i] = z;
						for (int s = 2 * t; s <= 2 * j; s++) {
							//print_ball_nt(mode, h, l, map, map_flag,map_change);
							cct_showstr(i * 4 - 2, s, "〇", z, COLOR_BLACK);
							if (s % 2 == 0) {
								cct_showstr(i * 4 - 2, s - 1, "═", COLOR_HWHITE, COLOR_BLACK);
							}
							else {
								cct_showstr(i * 4 - 2, s - 1, "  ", COLOR_HWHITE, COLOR_HWHITE);
							}
							Sleep(20);
						}

						break;
					}
				}
			}
		}
	}
	cct_setcolor();
}

void g_fill(int mode, int h, int l, int map[][11], int map_flag[][11], int map_change[][11])
{
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= l; j++) {
			if (map[i][j] == 0) {
				map[i][j] = rand() % 9 + 1;
				cct_showstr(j * 4 - 2, 2 * i, "〇", map[i][j], COLOR_BLACK);
			}
			Sleep(10);
			cct_setcolor();
		}
	}
}


void g_se(int mode, int h, int l, int map[][11], int map_flag[][11], int map_change[][11]) 
{
	search(mode, h, l, map, map_change);
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= l; j++) {
			if (map_change[i][j] == 1) {
				cct_showstr(j * 4 - 2, 2 * i, "◎", map[i][j], COLOR_BLACK);
			}
			cct_setcolor();
		}
	}
}

int g_sea(int mode, int h, int l, int map[][11], int map_flag[][11], int map_change[][11])
{
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= l; j++) {
			if (map_change[i][j] == 1) {
				return 1;
			}
		}
	}
	return 0;
}