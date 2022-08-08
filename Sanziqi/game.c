#define _CRT_SECURE_NO_WARNINGS
//这里是所有的自定义函数的实现  文件名game.c
#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
InitBoard(char board[ROW][COL], int row, int col)//初始化棋盘
{
	int i = 0;
	int j = 0;
	for (i = 0; i <= row; i++)
	{
		for (j = 0; j <= col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
dispalyBoard(char board[ROW][COL], int row, int col)//打印棋盘
{
	printf("+---+---+---+\n");
	int i = 0;
	for (i = 0; i < row; i++)
	{
		printf("| %c | %c | %c |\n", board[i][0], board[i][1], board[i][2]);
		printf("+---+---+---+\n");
	}
	printf("\n");
}
void playerMove(char board[ROW][COL], int row, int col)//玩家下棋
{
	int x = 0;
	int y = 0;
	printf("玩家下棋>:\n");
	while (1)
	{
		printf("请输入坐标>:");
		scanf("%d %d", &x, &y);
		//坐标是否合法;
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')//判断是否有落子
			{
				board[x - 1][y - 1] = 'x';
				break;
			}
		}
		else
		{
			printf("坐标被占用，请换位\n");
		}
	}
}

void ComputerMoce(char board[ROW][COL], int row, int col)
{
	printf("电脑下棋:>\n");
	int x = 0;
	int y = 0;


	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = 'o';
			break;
		}
	}
}
int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}
char Iswin(char board[ROW][COL], int row, int col)
{
	//判断行
	int i = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}
	}
	//判断列
	int j = 0;
	for (j = 0; j < col; j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[1][j] != ' ')
		{
			return board[1][j];
		}
	}
	//判断对角线
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	//判断是否平局
	if (IsFull(board, row, col))
	{
		return 'Q';//平局
	}
	return 'c';//继续游戏
}