/* 2351883 ��06 ������ */
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
	cct_setconsoleborder(120, 40, 120, 9000);
	while (1) {
		int mode = menu();
		int n = 0;
		char s = 0, d = 0;
		int speed = 0;
		char t = 0;
		if (mode == 0)
			break;
		if (mode !=5 ) {
			while (1) {
				cout << "�����뺺ŵ���Ĳ���(1-10)" << endl;
				cin >> n;
				if (cin.good() == 0) {
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					continue;
				}
				if (n < 1 || n>10) {
					cin.ignore(INT_MAX, '\n');
					continue;
				}
				cin.ignore(INT_MAX, '\n');
				break;
			}
			while (1) {
				cout << "��������ʼ��(A-C)" << endl;
				s = getchar();
				if (s >= 'a' && s <= 'c')
					s = s - 'a' + 'A';
				if (s < 'A' || s>'C') {
					cin.ignore(INT_MAX, '\n');
					continue;
				}
				cin.ignore(INT_MAX, '\n');
				break;
			}


			while (1) {
				cout << "������Ŀ����(A-C)" << endl;
				cin >> d;
				if (d >= 'a' && d <= 'c')
					d = d - 'a' + 'A';
				if (d < 'A' || d >'C') {
					cin.ignore(INT_MAX, '\n');
					continue;
				}
				if (d == s) {
					cout << "Ŀ����(" << d << ")��������ʼ��(" << s << ")��ͬ" << endl;
					cin.ignore(INT_MAX, '\n');
					continue;
				}
				cin.ignore(INT_MAX, '\n');
				break;
			}
			if (mode == 4||mode==8) {
				while (1) {
					cout << "�������ƶ��ٶ�(0-5: 0-���س�������ʾ 1-��ʱ� 5-��ʱ���)" << endl;
					cin >> speed;
					if (cin.good() == 0) {
						cin.clear();
						cin.ignore(INT_MAX, '\n');
						continue;
					}
					if (speed < 0 || speed>5) {
						cin.ignore(INT_MAX, '\n');
						continue;
					}
					cin.ignore(INT_MAX, '\n');
					break;
				}

			}
			t = 198 - s - d;
			open(n, s);
			hanoir(n, s, t, d, mode, speed);
		}
		if (mode == 5 ) {
			hanoir(n, s, t, d, mode, speed);
		}
		if (mode < 4) {
			cout << endl;
		}
		else {
			cct_gotoxy(0, 38);
		}
		con();
	}

	return 0;
}