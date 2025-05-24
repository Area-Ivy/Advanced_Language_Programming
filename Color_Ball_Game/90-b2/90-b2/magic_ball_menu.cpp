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

int menu() 
{
	cct_cls();
	cct_setconsoleborder(120, 30,120 , 200);
	cct_setfontsize("新宋体", 16);
	char n;
	cout << "---------------------------------" << endl;
	cout << "1.内部数组，生成初始状态，寻找是否有初始可消除项" << endl;
	cout << "2.内部数组，消除初始可消除项后非0项下落并用0填充" << endl;
	cout << "3.内部数组，消除初始可消除项后查找消除提示" << endl;
	cout << "4.n * n的框架(无分隔线)，显示初始状态" << endl;
	cout << "5.n * n的框架(有分隔线)，显示初始状态" << endl;
	cout << "6.n * n的框架(无分隔线)，显示初始状态及初始可消除项" << endl;
	cout << "7.n * n的框架(有分隔线)，消除初始可消除项后显示消除提示" << endl;
	cout << "8.cmd图形界面完整版(有分隔线，鼠标移动时显示坐标，右键退出)" << endl;
	cout << "9.cmd图形界面完整版" << endl;
	cout << "0.退出" << endl;
	cout << "---------------------------------" << endl;
	cout << "[请选择:] ";
	while (1) {
		n = _getch();
		if (n >= '1' && n <= '9') {
			cout << n;
			cct_cls();
			break;
		}
		if (n == '0') {
			cout << n;
			cct_gotoxy(0, 20);
			system("pause");
			break;
		}
	}
	return n - '0';
}