#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

	int num; 
	int *length, *last;
	char** ch1, **ch2;
	int z;				//���ڸ� ��� ������ �迭���� ���� ��Ÿ���� ���ڷ� ���
	int temp;

	scanf("%d", &num);							 //���ڿ� �迭���� �Է�
	getchar();
	ch1 = (char**)malloc(sizeof(char*) * num);     //���ڿ��迭�� ������ŭ �Ҵ�
	ch2 = (char**)malloc(sizeof(char*) * num);     //���ڿ��迭�� ������ŭ �Ҵ�
	length = (int*)malloc(sizeof(int*) * num);
	last = (int*)malloc(sizeof(int*) * num);

	for (int i = 0; i < num; i++)
	{
		ch1[i] = (char*)malloc(sizeof(char) * 20); //���ڿ� ���� �ִ� 20��ŭ �����Ҵ�
		ch2[i] = (char*)malloc(sizeof(char) * 20); //���ڿ� ���� �ִ� 20��ŭ �����Ҵ�
	}

	for (int j = 0; j < num; j++)
	{
		gets(ch1[j]);								//���ڿ� �Է�
		length[j] = strlen(ch1[j]);					//�� ���ڿ��� ��������
	}

	for (int i = 0; i < num; i++)
	{
		z = 0;											//�� �ε��� �ʱ�ȭ

		for (int j = 0; j < length[i]; j++)
		{
			if (ch1[i][j] >= 48 && ch1[i][j] <= 57)		//0~9������ �ƽ�Ű�ڵ�
			{
				ch2[i][z] = ch1[i][j];
				z++;									//���� ������ ���� �� �ε��� ����
			}
		}

	}


	for (int i = 0; i < num; i++)
	{
		last[i] = atoi(ch2[i]);
	}

	for (int j = 0; j < num; j++)
	{
		for (int i = j; i < num; i++)
		{
			if (last[i] > last[j])
			{
				temp = last[i];
				last[i] = last[j];
				last[j] = temp;
			}
		}
	}


	for (int i = 0; i < num; i++)
	{
		printf("%d\n", last[i]);
	}


}