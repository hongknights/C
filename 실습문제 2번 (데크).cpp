#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct node
{
	int elem;
	struct node* prev;
	struct node* next;
};

struct deque
{
	struct node* f;
	struct node* r;
};

void initQue(deque* q)
{
	q->r = NULL;
	q->f = NULL;
}

int isEmpty(deque* q)
{
	return (q->f == NULL);
}

struct node* getnode()
{
	struct node* p = (struct node*)malloc(sizeof(struct node) * 1);
	p->elem = -1;
	p->next = NULL;
	return p;
}


void add_front(deque* q, int X)
{
	struct node* p = getnode();
	p->elem = X;
	p->prev = NULL;
	p->next = NULL;


	if (isEmpty(q))
	{
		q->f = p;
		q->r = p;
	}

	else
	{
		p->next = q->f;
		q->f->prev = p;
		q->f = p;
	}
}



void add_rear(deque* q, int X)
{
	struct node* p = getnode();
	p->elem = X;
	p->prev = NULL;
	p->next = NULL;

	if (isEmpty(q))
	{
		q->f = p;
		q->r = p;
	}

	else
	{
		p->prev = q->r;
		q->r->next = p;
		q->r = p;
	}
}

void emptyQueueException()
{
	printf("underflow\n");
}

void putnode(struct node* p)
{
	free(p);
	p = NULL;
}

int delete_front(deque* q)
{
	int k;

	if (isEmpty(q))
	{
		emptyQueueException();
		k = -1;
		return k;
	}

	int e = q->f->elem;

	struct node* p = q->f;
	q->f = q->f->next;

	if (q->f == NULL)
		q->r = NULL;
	else
		q->f->prev = NULL;

	putnode(p);

	return e;
}


int delete_rear(deque* q)
{
	if (isEmpty(q))
	{
		emptyQueueException();
		return -1;
	}

	int e = q->r->elem;

	struct node* p = q->r;
	q->r = q->r->prev;

	if (q->r == NULL)
		q->f = NULL;
	else
		q->r->next = NULL;

	putnode(p);

	return e;
}


void traverse(deque* q)
{
	struct node* p = q->f;

	while (p != NULL)
	{
		printf(" %d", p->elem);
		p = p->next;
	}

	printf("\n");
}

int main()
{
	deque q;
	int operation_num;
	char oper[3];
	int data;

	scanf("%d", &operation_num);
	getchar();
	initQue(&q);


	for (int i = 0; i < operation_num; i++)
	{
		scanf("%s",oper);

		if (strcmp(oper, "AF") == 0)
		{
			scanf("%d", &data);
			add_front(&q, data);
			getchar();
		}

		else if (strcmp(oper, "AR") == 0)
		{
			scanf("%d", &data);
			add_rear(&q, data);
			getchar();
		}

		else if (strcmp(oper, "DF") == 0)
		{
			int k = delete_front(&q);

			if (k == -1)		//underflow 발생 시
			{
				return 0;		//main 함수 종료
			}

			getchar();
		}

		else if (strcmp(oper, "DR") == 0)
		{
			int k = delete_rear(&q);

			if (k == -1)		//underflow 발생 시
			{
				return 0;		//main 함수 종료
			}

			getchar();
		}

		else if (strcmp(oper, "P") == 0)
		{
			traverse(&q);
			getchar();
		}
	}

	return 0;
}
