/* 2351883 信06 陈奕名 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <tchar.h>
#include <string.h>
#include <Windows.h>
#include <conio.h>
#include "cmd_console_tools.h"
using namespace std;
/* ----------------------------------------------------------------------------------

	 本文件功能：
	1、放被 hanoi_main.cpp 调用的菜单函数，要求显示各菜单项，读入正确的选项后返回

	 本文件要求：
	1、不允许定义外部全局变量（const及#define不在限制范围内）
	2、不允许定义静态全局变量（全局变量的使用准则是：少用、慎用、能不用尽量不用）
	3、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
	4、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------------------------------------------------- */


int menu() {
	char n;
	cout << "---------------------------------" << endl;
	cout << "1.基本解" << endl;
	cout << "2.基本解(步数记录)" << endl;
	cout << "3.内部数组显示(横向)" << endl;
	cout << "4.内部数组显示(纵向 + 横向)" << endl;
	cout << "5.图形解 - 预备 - 画三个圆柱" << endl;
	cout << "6.图形解 - 预备 - 在起始柱上画n个盘子" << endl;
	cout << "7.图形解 - 预备 - 第一次移动" << endl;
	cout << "8.图形解 - 自动移动版本" << endl;
	cout << "9.图形解 - 游戏版" << endl;
	cout << "0.退出" << endl;
	cout << "---------------------------------" << endl;
	cout << "[请选择:] ";
	while (1) {
		n = _getch();
		if (n >= '0' && n <= '9') {
			cout << n;
			cout << endl;
			cout << endl;
			cout << endl;
			break;
		}
	}
	return n - '0';
}