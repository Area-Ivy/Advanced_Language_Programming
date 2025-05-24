/* 2351883 ��06 ������ */
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

void base(int mode, int h, int l, int map[][11], int map_flag[][11], int map_change[][11])
{
	if (mode == 1) {
		cout << "��ʼ����:" << endl;
		fill(h, l, map);
		print_map(mode, h, l, map, map_flag);
		cout << endl;
		int k = det_clean(mode, h, l, map, map_flag);
		if (!k) {
			cout << "��ʼ���޿�������"<<endl;
		}
		int x, y;
		cct_getxy(x, y);
		det_end(x, y);
	}
	if (mode == 2) {
		cout << "��ʼ����:" << endl;
		fill(h, l, map);
		print_map(mode, h, l, map, map_flag);
		int n = 1;
		while (1) {
			for (int i = 1; i <= h; i++) {
				for (int j = 1; j <= l; j++) {
					map_flag[i][j] = 0;
				}
			}
			int k = det_clean(mode, h, l, map, map_flag);
			if (!k) {
				if (n == 1) {
					cout << "��ʼ�޿��������С���޷����ԣ����ٴ�����" << endl;
				}
				else {
					cout << "��ʼ���޿�������" << endl;
				}
				int x, y;
				cct_getxy(x, y);
				det_end(x, y);
				break;
			}
			else {
				zero(mode, h, l, map, map_flag);
				cout << "���س���������ֵ��䣺" << endl;
				det_enter();
				fill(h, l, map);
				cout << "��ֵ���������(��ͬɫ��ʶ)��" << endl;
				print_map(mode, h, l, map, map_flag);
				memset(map_flag, 0, sizeof(map_flag));
				if (mark(h, l, map, map_flag) == 0) {
					cout << "��ʼ���޿�������" << endl;
					int x, y;
					cct_getxy(x, y);
					det_end(x, y);
					break;
				}
			}
			n++;
		}
	}
	if (mode == 3) {
		cout << "��ʼ����:" << endl;
		fill(h, l, map);
		print_map(mode, h, l, map, map_flag);
		while (1) {
			for (int i = 1; i <= h; i++) {
				for (int j = 1; j <= l; j++) {
					map_flag[i][j] = 0;
				}
			}
			int k = det_clean(mode, h, l, map, map_flag);
			if (!k) {
				cout << "��ʼ���޿�������" << endl;
				cout << endl;
				cout << "��ѡ���������ʾ(��ͬɫ��ʶ)��" << endl;
				search(mode, h, l, map, map_change);
				print_c(mode, h, l, map, map_change);
				int x, y;
				cct_getxy(x, y);
				det_end(x, y);
				break;
			}
			else {
				zero(mode, h, l, map, map_flag);
				cout << "���س���������ֵ��䣺" << endl;
				det_enter();
				fill(h, l, map);
				cout << "��ֵ���������(��ͬɫ��ʶ)��" << endl;
				print_map(mode, h, l, map, map_flag);
				memset(map_flag, 0, sizeof(map_flag));
				if (mark(h, l, map, map_flag) == 0) {
					cout << "��ʼ���޿�������" << endl;
					cout << endl;
					cout << "��ѡ���������ʾ(��ͬɫ��ʶ)��" << endl;
					search(mode, h, l, map, map_change);
					print_c(mode, h, l, map, map_change);
					int x, y;
					cct_getxy(x, y);
					det_end(x, y);
					break;
				}
			}
		}
	}
}

void print_map(int mode, int h, int l, int map[][11], int map_flag[][11])
{

	cout << "  " << "|  ";
	for (int i = 1; i <= l; i++) {
		cout << i << "  ";
	}
	cout << endl;
	cout << "--+-";
	for (int i = 1; i <= l; i++) {
		cout << "---";
	}
	cout << endl;
	for (int i = 1; i <= h; i++) {
		cout << char('A' + i - 1) << " " << "|  ";
		for (int j = 1; j <= l; j++) {
			if (map[i][j] == 0) {
				cct_setcolor(COLOR_HYELLOW, COLOR_BLACK);
				cout << map[i][j];
				cct_setcolor();
				cout << "  ";
			}
			else {
				if (map_flag[i][j] == 1) {
					cct_setcolor(COLOR_HYELLOW, COLOR_BLUE);
					cout << map[i][j];
					cct_setcolor();
					cout << "  ";
				}
				else {
					cout << map[i][j] << "  ";
				}
			}
		}
		cout << endl;
	}
	cout << endl;
}

void fill(int h, int l, int map[][11])
{
	srand((unsigned int)(time(0)));
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= l; j++) {
			if (map[i][j] == 0) {
				map[i][j] = rand() % 9 + 1;
			}
		}
	}
}

int det_clean(int mode, int h, int l, int map[][11], int map_flag[][11])
{
	cout << "���س�������Ѱ�ҳ�ʼ��������Ĳ���...";
	det_enter();
	int flag = mark(h, l, map, map_flag);
	if (flag) {
		cout << endl;
		cout << "��ʼ��������(��ͬɫ��ʶ)��" << endl;
		print_map(mode, h, l, map, map_flag);
		return 1;
	}
	else {
		return 0;
	}
}


int mark(int h, int l, int map[][11], int map_flag[][11]) 
{
	int flag = 0;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= l; j++) {
			if (map[i][j - 1] == map[i][j] && map[i][j + 1] == map[i][j]) {
				flag = 1;
				map_flag[i][j] = 1;
				map_flag[i][j - 1] = 1;
				map_flag[i][j + 1] = 1;
			}
			if (map[i - 1][j] == map[i][j] && map[i][j] == map[i + 1][j]) {
				flag = 1;
				map_flag[i][j] = 1;
				map_flag[i - 1][j] = 1;
				map_flag[i + 1][j] = 1;
			}
		}
	}
	return flag;
}
void zero(int mode, int h, int l, int map[][11], int map_flag[][11]) 
{
	cout << "���س������������0����..." << endl;
	det_enter();
	cout << "�����0�������(��ͬɫ��ʶ)��" << endl;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= l; j++) {
			if (map_flag[i][j] == 1) {
				map[i][j] = 0;
			}
		}
	}
	fall(mode, h, l, map, map_flag);
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= l; j++) {
			map_flag[i][j] = 0;
		}
	}
	print_map(mode, h, l, map, map_flag);
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= l; j++) {
			if (map[i][j] == 0) {
				map_flag[i][j] = 1;
			}
		}
	}
}

void fall(int mode, int h, int l, int map[][11], int map_flag[][11]) 
{
	for (int i = 1; i <= l; i++) {
		for (int j = h; j >= 1; j--) {
			if (map[j][i] == 0) {
				for (int k = j; k >= 1; k--) {
					if (map[k][i] != 0) {
						map[j][i] = map[k][i];
						map[k][i] = 0;
						break;
					}
				}
			}
		}
	}
}

void search(int mode, int h, int l, int map[][11], int map_change[][11]) 
{
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= l; j++) {
			if (map[i - 1][j] == map[i][j - 1] && map[i - 1][j] == map[i][j + 1]) {
				map_change[i][j] = 1;
				map_change[i - 1][j] = 1;
			}
			if (map[i + 1][j] == map[i][j - 1] && map[i + 1][j] == map[i][j + 1]) {
				map_change[i][j] = 1;
				map_change[i + 1][j] = 1;
			}
			if (map[i][j - 1] == map[i - 1][j] && map[i][j - 1] == map[i + 1][j]) {
				map_change[i][j] = 1;
				map_change[i][j - 1] = 1;
			}
			if (map[i][j + 1] == map[i - 1][j] && map[i][j + 1] == map[i + 1][j]) {
				map_change[i][j] = 1;
				map_change[i][j + 1] = 1;
			}
		}
	}

	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= l; j++) {
			if (j >= 2) {
				if (map[i - 1][j] == map[i][j - 1] && map[i - 1][j] == map[i][j - 2]) {
					map_change[i - 1][j] = 1;
					map_change[i][j] = 1;
				}
				if (map[i + 1][j] == map[i][j - 1] && map[i + 1][j] == map[i][j - 2]) {
					map_change[i + 1][j] = 1;
					map_change[i][j] = 1;
				}
				if (map[i][j + 1] == map[i][j - 1] && map[i][j + 1] == map[i][j - 2]) {
					map_change[i][j + 1] = 1;
					map_change[i][j] = 1;
				}
			}
			if (j <= l - 2) {
				if (map[i - 1][j] == map[i][j + 1] && map[i - 1][j] == map[i][j + 2]) {
					map_change[i - 1][j] = 1;
					map_change[i][j] = 1;
				}
				if (map[i + 1][j] == map[i][j + 1] && map[i + 1][j] == map[i][j + 2]) {
					map_change[i + 1][j] = 1;
					map_change[i][j] = 1;
				}
				if (map[i][j - 1] == map[i][j + 1] && map[i][j - 1] == map[i][j + 2]) {
					map_change[i][j - 1] = 1;
					map_change[i][j] = 1;
				}
			}
			if (i >= 2) {
				if (map[i][j - 1] == map[i - 1][j] && map[i][j - 1] == map[i - 2][j]) {
					map_change[i][j - 1] = 1;
					map_change[i][j] = 1;
				}
				if (map[i][j + 1] == map[i - 1][j] && map[i][j + 1] == map[i - 2][j]) {
					map_change[i][j + 1] = 1;
					map_change[i][j] = 1;
				}
				if (map[i + 1][j] == map[i - 1][j] && map[i + 1][j] == map[i - 2][j]) {
					map_change[i + 1][j] = 1;
					map_change[i][j] = 1;
				}
			}
			if (i <= h - 2) {
				if (map[i][j - 1] == map[i + 1][j] && map[i][j - 1] == map[i + 2][j]) {
					map_change[i][j - 1] = 1;
					map_change[i][j] = 1;
				}
				if (map[i][j + 1] == map[i + 1][j] && map[i][j + 1] == map[i + 2][j]) {
					map_change[i][j + 1] = 1;
					map_change[i][j] = 1;
				}
				if (map[i - 1][j] == map[i + 1][j] && map[i - 1][j] == map[i + 2][j]) {
					map_change[i - 1][j] = 1;
					map_change[i][j] = 1;
				}
			}
		}
	}
}

void print_c(int mode, int h, int l, int map[][11], int map_change[][11]) 
{
	cout << "  " << "|  ";
	for (int i = 1; i <= l; i++) {
		cout << i << "  ";
	}
	cout << endl;
	cout << "--+-";
	for (int i = 1; i <= l; i++) {
		cout << "---";
	}
	cout << endl;
	for (int i = 1; i <= h; i++) {
		cout << char('A' + i - 1) << " " << "|  ";
		for (int j = 1; j <= l; j++) {
			if (map[i][j] == 0) {
				cct_setcolor(COLOR_HYELLOW, COLOR_BLACK);
				cout << map[i][j];
				cct_setcolor();
				cout << "  ";
			}
			else {
				if (map_change[i][j] == 1) {
					cct_setcolor(COLOR_HYELLOW, COLOR_BLUE);
					cout << map[i][j];
					cct_setcolor();
					cout << "  ";
				}
				else {
					cout << map[i][j] << "  ";
				}
			}
		}
		cout << endl;
	}
	cout << endl;
}