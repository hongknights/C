#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Que
{
	int f;		//front
	int r;		//rear
	int* Q;		//원형배열
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
		q->Q[i] = 0;				//초기화
	}
	q->f = 0; //0		//주의사항
	q->r = 0; //N-1;	//주의사항
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
		return -1;		//주의사항
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
		return -1;	//주의사항
	}

	q->f = (q->f + 1) % N;
	q->Q[q->f] = 0;			//주의사항 : 삭제 후 초기화 하지 않으면 삭제하지 않은 효과

	return 0;

}


int main()
{
	Que p;

	int *q;					//원형 큐 크기
	int n;					//연산 실행횟수
	char oper;				//연산 종류
	int data;
		
	q = (int*)malloc(sizeof(int) * 1);		//N 동적할당

	scanf("%d", q);				//원형 큐 크기 (첫째 줄 입력)

	if (*q == 0)
	{
		printf("Error!!\n");
		return 0;
	}

	scanf("%d", &n);	//연산 실행횟수(둘째 줄 입력)

	getchar();
	initQue(&p, *q);

	for (int i = 0; i < n; i++)
	{
		scanf("%c", &oper);

		if (oper == 'I')
		{
			scanf("%d", &data);

			int k = enqueue(&p, *q, data);

			if (k == -1)		//overflow 발생 시
			{
				return 0;		//main 함수 종료
			}

			getchar();
		}

		else if (oper == 'D')
		{
			int k = dequeue(&p, *q);

			if (k == -1)		//overflow 발생 시
			{
				return 0;		//main 함수 종료
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