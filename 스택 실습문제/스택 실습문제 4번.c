#define _CRT_SECURE_NO_WARNINGS
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

int isEmpty(struct stack* s)
{
	return (s->top == NULL);
}

void emptyStackException()
{
	printf("StackException\n");
}

void putnode(struct node* p)
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
//////////////////////////////////////////////////////////////

int isOperand(char s)
{
	char oper[10] = { '0','1','2','3','4','5','6','7','8','9' };

	for (int i = 0; i < 10; i++)
	{
		if (s == oper[i])
			return 1;
	}

	return 0;
}

int doOperator(char op, int x, int y)
{
	int v=0;

	switch (op)
	{
	case '+': v = x + y; break;
	case '-': v = x - y; break;
	case '*': v = x * y; break;
	case '/': v = x / y; break;

	}


	return v;
}

void write(char s)
{
	printf("%d ", s - '0');
}
void evaluate(char* postfix_array)
{
	struct stack S;
	initStack(&S);


	int N = strlen(postfix_array);
	int idx = 0;

	while (idx != N)
	{
		char s = postfix_array[idx++];
		if (isOperand(s))
		{
			push(&S, s);
		}
		else //s가 연산자 일 때
		{
			int a = pop(&S) - '0';
			int b = pop(&S) - '0';


			push(&S, doOperator(s, b, a) + '0');
		}
		//traverse(&S); //연산과정 확인
	}

	write(pop(&S));

	printf("\n");
	return;


}

int main()
{
	char array[100];
	int num;

	scanf("%d", &num);
	getchar();

	for (int i = 0; i < num; i++)
	{
		gets(array);
		evaluate(array);
	}

	printf("\n");

	return 0;
}