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
	return ((q->r + 1) % N == q->f);
} 

int isFull(Que* q, int N)
{
	return ((q->r + 2) % N == q->f);
}


void initQue(Que* q, int N)
{
	q->Q = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; i++)
	{
		q->Q[i] = 0;				//�ʱ�ȭ
	}
	q->f = 1; //0		//���ǻ���
	q->r = 0; //N-1;	//���ǻ���
}

void fullQueueException()
{
	printf("overflow\n");
}

void enqueue(Que* q, int N, int e)
{
	if (isFull(q, N))
	{
		fullQueueException();
		return;		//���ǻ���
	}

	q->r = (q->r + 1) % N;
	q->Q[q->r] = e;
}

void emptyQueueException()
{
	printf("underflow\n");
}

int dequeue(Que* q, int N)
{
	if (isEmpty(q, N))
	{
		emptyQueueException();
		return -1;	//���ǻ���
	}

	int e = q->Q[q->f];
	q->Q[q->f] = 0;			//���ǻ��� : ���� �� �ʱ�ȭ ���� ������ �������� ���� ȿ��
	q->f = (q->f + 1) % N;
	return e;
}

void traverse(Que* q, int N)
{
	for (int i = 0; i < N; i++)
	{
		int e = q->Q[i];
		printf("%d ", e);
	}

	printf("\n");
}

int main()
{
	Que q;

	int N = 0;
	int iter = 0;

	scanf("%d", &N);
	scanf("%d", &iter);

	initQue(&q, N);

	enqueue(&q, N, 10);
	enqueue(&q, N, 20);
	traverse(&q, N);

	enqueue(&q, N, 30);
	enqueue(&q, N, 40);
	traverse(&q, N);

	dequeue(&q, N);
	traverse(&q, N);

	enqueue(&q, N, 50);
	enqueue(&q, N, 60);
	enqueue(&q, N, 70);
	traverse(&q, N);

	printf("\n");

	return 0;
}