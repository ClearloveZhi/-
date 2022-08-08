#define _CRT_SECURE_NO_WARNINGS
//这里是定义的头文件以及声明 头文件名game.h
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 3
#define COL 3
//初始化棋盘
InitBoard(char board[ROW][COL], int row, int col);
//打印棋盘
dispalyBoard(char board[ROW][COL], int row, int col);
//玩家下棋
void playerMove(char board[ROW][COL], int row, int col);
//电脑下棋
void ComputerMoce(char board[ROW][COL], int row, int col);
//判断输赢
char Iswin(char board[ROW][COL], int row, int col);