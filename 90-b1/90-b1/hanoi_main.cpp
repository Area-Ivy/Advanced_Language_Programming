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
/* ----------------------------------------------------------------------------------

	 本文件功能：
	1、放main函数
	2、初始化屏幕
	3、调用菜单函数（hanoi_menu.cpp中）并返回选项
	4、根据选项调用菜单各项对应的执行函数（hanoi_multiple_solutions.cpp中）

	 本文件要求：
	1、不允许定义全局变量（含外部全局和静态全局，const及#define不在限制范围内）
	2、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
	3、按需加入系统头文件、自定义头文件、命名空间等

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
				cout << "请输入汉诺塔的层数(1-10)" << endl;
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
				cout << "请输入起始柱(A-C)" << endl;
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
				cout << "请输入目标柱(A-C)" << endl;
				cin >> d;
				if (d >= 'a' && d <= 'c')
					d = d - 'a' + 'A';
				if (d < 'A' || d >'C') {
					cin.ignore(INT_MAX, '\n');
					continue;
				}
				if (d == s) {
					cout << "目标柱(" << d << ")不能与起始柱(" << s << ")相同" << endl;
					cin.ignore(INT_MAX, '\n');
					continue;
				}
				cin.ignore(INT_MAX, '\n');
				break;
			}
			if (mode == 4||mode==8) {
				while (1) {
					cout << "请输入移动速度(0-5: 0-按回车单步演示 1-延时最长 5-延时最短)" << endl;
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