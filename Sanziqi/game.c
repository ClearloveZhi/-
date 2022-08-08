#define _CRT_SECURE_NO_WARNINGS
//���������е��Զ��庯����ʵ��  �ļ���game.c
#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
InitBoard(char board[ROW][COL], int row, int col)//��ʼ������
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
dispalyBoard(char board[ROW][COL], int row, int col)//��ӡ����
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
void playerMove(char board[ROW][COL], int row, int col)//�������
{
	int x = 0;
	int y = 0;
	printf("�������>:\n");
	while (1)
	{
		printf("����������>:");
		scanf("%d %d", &x, &y);
		//�����Ƿ�Ϸ�;
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')//�ж��Ƿ�������
			{
				board[x - 1][y - 1] = 'x';
				break;
			}
		}
		else
		{
			printf("���걻ռ�ã��뻻λ\n");
		}
	}
}

void ComputerMoce(char board[ROW][COL], int row, int col)
{
	printf("��������:>\n");
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
	//�ж���
	int i = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}
	}
	//�ж���
	int j = 0;
	for (j = 0; j < col; j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[1][j] != ' ')
		{
			return board[1][j];
		}
	}
	//�ж϶Խ���
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	//�ж��Ƿ�ƽ��
	if (IsFull(board, row, col))
	{
		return 'Q';//ƽ��
	}
	return 'c';//������Ϸ
}