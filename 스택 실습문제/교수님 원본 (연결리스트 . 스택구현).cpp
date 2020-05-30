#define _CRT_SECURE_NO_WARININGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct node
{
	int elem;
	struct node* next;
};

struct stack
{
	struct node* top;
};

void initStack(struct stack* s)
{
	s->top = NULL;
	return;
}

struct node* getNode()
{
	struct node* p = (struct node*)malloc(sizeof(struct node) * 1);
	p->elem = -1;
	p->next = NULL;
	return p;
}

void push(struct stack* s, int e)
{
	struct node* p = getNode();
	p->elem = e;
	p->next = s->top;
	s->top = p;
	return;
}

int isEmpty(struct stack *s)
{
	return (s->top == NULL);
}

void emptyStackException()
{
	printf("StackException\n");
}

void putnode(struct node *p)
{
	free(p);
	p = NULL;
}

int pop(struct stack* s)
{
	if (isEmpty(s))
	{
		emptyStackException();
		return -1;
	}

	int e = s->top->elem;
	struct node* p = s->top;
	s->top = s->top->next;
	putnode(p);
	return e;
}

void visit(int e)
{
	printf("%c ", e);
}


void traverse(struct stack* s)
{
	struct node* p = s->top;

	while (p != NULL)
	{
		visit(p->elem);
		p = p->next;
	}
	printf("\n");
}

int main()
{
	//push C, push B, push A, push X
	//traverse  ===>   X A B C

	struct stack S;
	initStack(&S);

	push(&S, 'C');
	push(&S, 'B');
	push(&S, 'A');
	push(&S, 'X');


	traverse(&S);

	return 0;
}