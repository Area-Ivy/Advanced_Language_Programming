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
/* ----------------------------------------------------------------------------------

	 ���ļ����ܣ�
	1����main����
	2����ʼ����Ļ
	3�����ò˵�������hanoi_menu.cpp�У�������ѡ��
	4������ѡ����ò˵������Ӧ��ִ�к�����hanoi_multiple_solutions.cpp�У�

	 ���ļ�Ҫ��
	1����������ȫ�ֱ��������ⲿȫ�ֺ;�̬ȫ�֣�const��#define�������Ʒ�Χ�ڣ�
	2����̬�ֲ����������������ƣ���ʹ��׼��Ҳ�ǣ����á����á��ܲ��þ�������
	3���������ϵͳͷ�ļ����Զ���ͷ�ļ��������ռ��

   ----------------------------------------------------------------------------------- */

int main()
{
	//cct_setconsoleborder(120, 40, 120, 9000);
	while (1) {
		int mode = menu();
		int h = 0, l = 0;
		int map[11][11] = { 0 };
		int map_flag[11][11] = { 0 };
		int map_change[11][11] = { 0 };
		if (mode == 0)
			break;
		while (1) {
			cout << "����������(5-9)" << endl;
			cin >> h;
			if (cin.good() == 0) {
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				continue;
			}
			if (h < 5 || h >9) {
				cin.ignore(INT_MAX, '\n');
				continue;
			}
			cin.ignore(INT_MAX, '\n');
			break;
		}
		while (1) {
			cout << "����������(5-9)" << endl;
			cin >> l;
			if (cin.good() == 0) {
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				continue;
			}
			if (l < 5 || l >9) {
				cin.ignore(INT_MAX, '\n');
				continue;
			}
			cin.ignore(INT_MAX, '\n');
			break;
		}
		cout << endl;
		if (mode >= 1 && mode <= 3) {
			base(mode, h, l, map,map_flag,map_change);
		}
		if (mode >= 4 && mode <= 9) {
			graph(mode, h, l, map, map_flag, map_change);
		}
	}
	return 0;
}