#define _CRT_SECURE_NO_WARNINGS
//�����Ƕ����ͷ�ļ��Լ����� ͷ�ļ���game.h
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 3
#define COL 3
//��ʼ������
InitBoard(char board[ROW][COL], int row, int col);
//��ӡ����
dispalyBoard(char board[ROW][COL], int row, int col);
//�������
void playerMove(char board[ROW][COL], int row, int col);
//��������
void ComputerMoce(char board[ROW][COL], int row, int col);
//�ж���Ӯ
char Iswin(char board[ROW][COL], int row, int col);