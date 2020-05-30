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
/////////////////////////////////////////////////////////////////////
//피연산자는 0~9 한자리 숫자만 입력한다고 가정합니다.
//연산자 : + - x / ( )
int isOperand(char s)
{
	char oper[10] = { '0','1','2','3','4','5','6','7','8','9' };
	char oper_e[10] = { 'a', 'b' ,'c','d','e','f','g','h','i','j' };

	for (int i = 0; i < 10; i++)
	{
		if (s == oper_e[i])
			return 1;
	}


	for (int i = 0; i < 10; i++)
	{
		if (s == oper[i])
			return 1;
	}

	return 0;
}
 
int strfind(char* str, char s)
{
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == s)
			return i;
	}
	return 0;       
}

int getPrior(char s)
{
	char Prior[5] = { '(', '+', '-', 'x', '/' };
	char Prior_N[5] = { 0,1,1,2,2 };

	return Prior_N[ strfind(Prior, s) ];
}

char top(struct stack* s) 
{
	if (s->top == NULL)
	{
		emptyStackException();
		return -1;
	}

	return s->top->elem;
}

void write(char s) 
{
	printf("%c ", s);
}

void convert(char* infix_array)
{
	struct stack S;
	initStack(&S);

	int N = strlen(infix_array);
	int idx = 0;


	while (idx != N)
	{
		char s = infix_array[idx++];

		if ( isOperand(s)) //피연산자 처리구문
			write(s);

		else if (s == '(')
			push(&S, s);

		else if (s == ')')
		{
			while (top(&S) != '(')
				write(pop(&S));
			pop(&S);
		}
		else //연산자 처리구문
		{
			while (!isEmpty(&S) && (getPrior(s) <= getPrior(top(&S))))
				write(pop(&S));
			push(&S, s);
		}

	}


	while (!isEmpty(&S))
		write(pop(&S));

	 return;

}



int main()
{
	char infix_array[100] = "a-b-c+(d+exf)/g";
	convert(infix_array);
	printf("\n");
}