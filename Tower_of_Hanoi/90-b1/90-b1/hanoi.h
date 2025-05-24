/* 2351883 信06 陈奕名 */
#pragma once

/* ------------------------------------------------------------------------------------------------------

	 本文件功能：
	1、为了保证 hanoi_main.cpp/hanoi_menu.cpp/hanoi_multiple_solutions.cpp 能相互访问函数的函数声明
	2、一个以上的cpp中用到的宏定义（#define）或全局只读（const）变量，个数不限
	3、可以参考 cmd_console_tools.h 的写法（认真阅读并体会）
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