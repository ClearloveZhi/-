#define _CRT_SECURE_NO_WARNINGS
//�����Ǵ���������߼� �ļ���Ϊtest.c
#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
void meat()
{
	printf("---------------------\n");
	printf("-----1.��ʼ��Ϸ------\n");
	printf("-----2.�˳���Ϸ------\n");
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
		playerMove(board, ROW, COL);//�������
		ret = Iswin(board, ROW, COL);//�ж���Ӯ
		if (ret != 'c')
		{
			break;
		}
		dispalyBoard(board, ROW, COL);//��ӡ����
		ComputerMoce(board, ROW, COL);//��������
		ret = Iswin(board, ROW, COL);//�ж���Ӯ
		if (ret != 'c')
		{
			break;
		}
		dispalyBoard(board, ROW, COL);//��ӡ����
	}

	if (ret == 'x')
	{
		printf("���Ӯ�ˣ�\n");
	}
	else if (ret == 'o')
	{
		printf("����Ӯ�ˣ�\n");
	}
	else
	{
		printf("ƽ��\n");
	}
	dispalyBoard(board, ROW, COL);

}

int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do {
		meat();
		printf("��ѡ��>:");
		scanf("%d", &input);
		if (input == 1)
		{
			game();
		}
		else if (input == 0)
		{
			printf("�˳���Ϸ\n");
		}
		else
		{
			printf("������ѡ��\n");
		}

	} while (input);

	return 0;
}