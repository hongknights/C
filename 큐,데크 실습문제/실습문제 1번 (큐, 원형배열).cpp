#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Que
{
	int f;		//front
	int r;		//rear
	int* Q;		//�����迭
};

int isEmpty(Que* q, int N)
{
	return ((q->r) % N == q->f);
}

int isFull(Que* q, int N)
{
	return ((q->r + 1) % N == q->f);
}


void initQue(Que* q, int N)
{
	q->Q = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; i++)
	{
		q->Q[i] = 0;				//�ʱ�ȭ
	}
	q->f = 0; //0		//���ǻ���
	q->r = 0; //N-1;	//���ǻ���
}

void fullQueueException()
{
	printf("overflow");
}


void emptyQueueException()
{
	printf("underflow\n");
}

void traverse(Que* q, int N)
{
	for (int i = 0; i < N; i++)
	{
		int e = q->Q[i];
		printf(" %d", e);
	}

	printf("\n");
}

int enqueue(Que* q, int N, int e)
{
	if (isFull(q, N))
	{
		fullQueueException();
		traverse(q,N);
		return -1;		//���ǻ���
	}

	q->r = (q->r + 1) % N;
	q->Q[q->r] = e;

	return 0;
}

int dequeue(Que* q, int N)
{
	if (isEmpty(q, N))
	{
		emptyQueueException();
		return -1;	//���ǻ���
	}

	q->f = (q->f + 1) % N;
	q->Q[q->f] = 0;			//���ǻ��� : ���� �� �ʱ�ȭ ���� ������ �������� ���� ȿ��

	return 0;

}


int main()
{
	Que p;

	int *q;					//���� ť ũ��
	int n;					//���� ����Ƚ��
	char oper;				//���� ����
	int data;
		
	q = (int*)malloc(sizeof(int) * 1);		//N �����Ҵ�

	scanf("%d", q);				//���� ť ũ�� (ù° �� �Է�)

	if (*q == 0)
	{
		printf("Error!!\n");
		return 0;
	}

	scanf("%d", &n);	//���� ����Ƚ��(��° �� �Է�)

	getchar();
	initQue(&p, *q);

	for (int i = 0; i < n; i++)
	{
		scanf("%c", &oper);

		if (oper == 'I')
		{
			scanf("%d", &data);

			int k = enqueue(&p, *q, data);

			if (k == -1)		//overflow �߻� ��
			{
				return 0;		//main �Լ� ����
			}

			getchar();
		}

		else if (oper == 'D')
		{
			int k = dequeue(&p, *q);

			if (k == -1)		//overflow �߻� ��
			{
				return 0;		//main �Լ� ����
			}
			getchar();
		}
		else if (oper == 'P')
		{
			traverse(&p, *q);
			getchar();
		}
		
	}

	return 0;
}