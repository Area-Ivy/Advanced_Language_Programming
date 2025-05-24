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
			cout << "请输入行数(5-9)" << endl;
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
			cout << "请输入列数(5-9)" << endl;
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