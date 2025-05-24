/* 2351883 ĞÅ06 ³ÂŞÈÃû */
#pragma once

int menu();
void base(int mode, int h, int l, int map[][11], int map_flag[][11],int map_change[][11]);
void print_map(int mode, int h, int l, int map[][11], int map_flag[][11]);
void fill(int h, int l, int map[][11]);
void det_enter();
void det_end(int x, int y);
int det_clean(int mode, int h, int l, int map[][11], int map_flag[][11]);
int mark(int h, int l, int map[][11], int map_flag[][11]);
void zero(int mode, int h, int l, int map[][11], int map_flag[][11]);
void fall(int mode, int h, int l, int map[][11], int map_flag[][11]);
void search(int mode, int h, int l, int map[][11], int map_change[][11]);
void print_c(int mode, int h, int l, int map[][11], int map_change[][11]);
void graph(int mode, int h, int l, int map[][11], int map_flag[][11], int map_change[][11]);
void print_ball(int mode, int h, int l, int map[][11], int map_flag[][11], int map_change[][11]);
int g_mark(int mode, int h, int l, int map[][11], int map_flag[][11]);
void g_clear(int mode, int h, int l, int map[][11], int map_flag[][11]);
void g_fall(int mode, int h, int l, int map[][11], int map_flag[][11], int map_change[][11]);
void g_fill(int mode, int h, int l, int map[][11], int map_flag[][11], int map_change[][11]);
void g_se(int mode, int h, int l, int map[][11], int map_flag[][11], int map_change[][11]);
int sum(int mode, int h, int l, int map[][11], int map_flag[][11]);
void p_ball(int mode, int h, int l, int map[][11], int map_flag[][11], int map_change[][11]);
int g_sea(int mode, int h, int l, int map[][11], int map_flag[][11], int map_change[][11]);