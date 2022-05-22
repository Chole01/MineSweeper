#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<windows.h>

#define _ROW_ 15
#define _COL_ 15
#define _ROWS_ 16
#define _COLS_ 16
#define NUM_MINE 45
#define DIAMOND 4 //ascii '4'-->'♦'
#define MINE 15 //ascii '15'-->'☼'
#define SPACE ' '


void Banner();
void Mine_Zone(int row, int col, char arry_matrix[_ROW_][_COL_]);
void Matrix_Zone(int row, int col, char arry_matrix[_ROWS_][_COLS_]);
void InitMatrix(char arry[_ROWS_][_COLS_], char c);
void InitMine(char arry[_ROW_][_COL_], char c);
void InitGame(char arry_mine[_ROW_][_COL_],char arry_matrix[_ROWS_][_COLS_]);
void PlayGame(char arry_mine[_ROW_][_COL_],char arry_matrix[_ROWS_][_COLS_]);
void srand(unsigned int seed);// random number
int Num_Mine(int x, int y, char arry_mine[_ROW_][_COL_], char arry_matrix[_ROWS_][_COLS_]);
void Spread(int x, int y, char arry_mine[_ROW_][_COL_], char arry_matrix[_ROWS_][_COLS_]);
void GameOver(char arry_mine[_ROW_][_COL_], char arry_matrix[_ROWS_][_COLS_]);