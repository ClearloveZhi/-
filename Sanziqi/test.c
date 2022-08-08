#define _CRT_SECURE_NO_WARNINGS
//这里是代码的整体逻辑 文件名为test.c
#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
void meat()
{
	printf("---------------------\n");
	printf("-----1.开始游戏------\n");
	printf("-----2.退出游戏------\n");
	printf("---------------------\n");
	printf("---------------------\n");
}
void game()
{
	char ret = 0;
	char board[ROW][COL] = { 0 };
	InitBoard(board, ROW, COL);
	dispalyBoard(board, ROW, COL);
	while (1)
	{
		playerMove(board, ROW, COL);//玩家下棋
		ret = Iswin(board, ROW, COL);//判断输赢
		if (ret != 'c')
		{
			break;
		}
		dispalyBoard(board, ROW, COL);//打印棋盘
		ComputerMoce(board, ROW, COL);//电脑下棋
		ret = Iswin(board, ROW, COL);//判断输赢
		if (ret != 'c')
		{
			break;
		}
		dispalyBoard(board, ROW, COL);//打印棋盘
	}

	if (ret == 'x')
	{
		printf("玩家赢了！\n");
	}
	else if (ret == 'o')
	{
		printf("电脑赢了！\n");
	}
	else
	{
		printf("平局\n");
	}
	dispalyBoard(board, ROW, COL);

}

int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do {
		meat();
		printf("请选择>:");
		scanf("%d", &input);
		if (input == 1)
		{
			game();
		}
		else if (input == 0)
		{
			printf("退出游戏\n");
		}
		else
		{
			printf("请重新选择\n");
		}

	} while (input);

	return 0;
}