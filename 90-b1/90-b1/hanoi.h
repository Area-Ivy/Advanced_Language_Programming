/* 2351883 ��06 ������ */
#pragma once

/* ------------------------------------------------------------------------------------------------------

	 ���ļ����ܣ�
	1��Ϊ�˱�֤ hanoi_main.cpp/hanoi_menu.cpp/hanoi_multiple_solutions.cpp ���໥���ʺ����ĺ�������
	2��һ�����ϵ�cpp���õ��ĺ궨�壨#define����ȫ��ֻ����const����������������
	3�����Բο� cmd_console_tools.h ��д���������Ķ�����ᣩ
   ------------------------------------------------------------------------------------------------------ */

int menu();
void p(int n, char src, char tmp, char dst, int mode, int speed);
void con();
void hanoi(int n, char src, char tmp, char dst, int mode, int speed);
void move(char src, char dst);
void sc(char src, char tmp, char dst);
void open(int n, char s);
void hanoir(int n, char src, char tmp, char dst, int mode, int speed);
void yidong(int flag);
void delay(int speed);
void zhu();
void pan(int n);
void movep(int n, char src, char tmp, char dst, int mode, int speed);
void handmove(int n, char src, char tmp, char dst, int mode, int speed);


#define ZHU_A		10	
#define ZHU_B		20	
#define ZHU_C		30