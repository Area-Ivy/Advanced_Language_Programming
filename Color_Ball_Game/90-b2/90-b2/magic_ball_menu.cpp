/* 2351883 ��06 ������ */
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
	cct_setfontsize("������", 16);
	char n;
	cout << "---------------------------------" << endl;
	cout << "1.�ڲ����飬���ɳ�ʼ״̬��Ѱ���Ƿ��г�ʼ��������" << endl;
	cout << "2.�ڲ����飬������ʼ����������0�����䲢��0���" << endl;
	cout << "3.�ڲ����飬������ʼ������������������ʾ" << endl;
	cout << "4.n * n�Ŀ��(�޷ָ���)����ʾ��ʼ״̬" << endl;
	cout << "5.n * n�Ŀ��(�зָ���)����ʾ��ʼ״̬" << endl;
	cout << "6.n * n�Ŀ��(�޷ָ���)����ʾ��ʼ״̬����ʼ��������" << endl;
	cout << "7.n * n�Ŀ��(�зָ���)��������ʼ�����������ʾ������ʾ" << endl;
	cout << "8.cmdͼ�ν���������(�зָ��ߣ�����ƶ�ʱ��ʾ���꣬�Ҽ��˳�)" << endl;
	cout << "9.cmdͼ�ν���������" << endl;
	cout << "0.�˳�" << endl;
	cout << "---------------------------------" << endl;
	cout << "[��ѡ��:] ";
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