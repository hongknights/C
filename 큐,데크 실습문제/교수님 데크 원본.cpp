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
	printf("EmptyQueueException\n");
}

void putnode(struct node* p)
{
	free(p);
	p = NULL;
}

int delete_front(deque *q)
{
	if (isEmpty(q))
	{
		emptyQueueException();
		return -1;
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

	initQue(&q);

	add_front(&q, 10);
	add_front(&q, 20);
	add_front(&q, 30);
	add_rear(&q, 40);
	add_rear(&q, 50);
	traverse(&q);

	delete_front(&q);
	delete_front(&q);
	delete_rear(&q);
	traverse(&q);

	delete_front(&q);
	delete_rear(&q);
	delete_rear(&q);
	traverse(&q);

	printf("\n");

	return 0;
}
