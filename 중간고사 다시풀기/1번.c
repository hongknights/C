#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

	int n;
	int** matrix;
	int max = -1;									//1�� ������ ���� ���� ���� ���� ��� ���� ���� ���ȣ�� ���� ���ؼ� -1 �� �ʱ�ȭ
	int row = 0;

	scanf("%d", &n);

	matrix = (int**)malloc(sizeof(int*) * n);

	for (int i = 0; i < n; i++)
	{
		matrix[i] = (int*)malloc(sizeof(int) * n);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &matrix[i][j]);				//��� ���� �Է�
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = max+1; j < n; j++)				//�ึ�� �� �������� ���� �Ǵ� �� ��ȣ+1 �ε������� Ž�� ����
		{
			if (matrix[i][j] == 1)					//���� �� �������� ���� �Ǵ� �ຸ�� 1�� ������ ���ٸ�
			{
				max=j;								//�ִ� 1�� ���� ����
				row = i;							//�ش� �� ��ȣ ����
			}
		}
	}

	printf("%d\n", row);

	return 0;
}

//mostOnes(A,n)
//for i <- 0 to i <- n
	//for j <- -1 to j <- n
		//if (matrix[i][j] == 1)
			//max = j
			//row = i