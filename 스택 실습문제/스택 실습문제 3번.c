#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct node
{
	char elem;
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

char pop(struct stack* s)
{
	if (isEmpty(s))
	{
		emptyStackException();
		return -1;
	}

	char e = s->top->elem;
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
	char oper_e[10] = { 'A', 'B' ,'C','D','E','F','G','H','I','J' };

	for (int i = 0; i < 10; i++)
	{
		if (s == oper_e[i])
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
	char Prior[13] = { '(','|', '&','>','<', '+', '-', '*', '/' ,'!','@','#'};
	char Prior_N[13] = { 0,1,2,3,3,4,4,5,5,6,6,6};

	return Prior_N[strfind(Prior, s)];
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


	if (s == '|')
		printf("|%c", s);

	else if (s == '&')
		printf("&%c", s);

	else if (s == '@')
		printf("+");

	else if (s == '#')
		printf("-");
	else
		printf("%c", s);

}

void convert(char* infix_array)
{
	struct stack S;
	initStack(&S);

	int N = strlen(infix_array);
	int idx = 0;
	int id = 0;
	int i=2;


	while (id != N)
	{
		if (infix_array[id] == '&')
		{
			infix_array[id] = ' ';
			id = id + 2;
		}

		else if (infix_array[id] == '|')
		{
			infix_array[id] = ' ';
			id = id + 2;
		}

		else if (infix_array[id] == '+')
		{
			if(id>0 && infix_array[id-1] != ')')
				i = isOperand(infix_array[id - 1]);

			if (i == 0 || id == 0)
				infix_array[id] = '@';
			else if (i == 1)
				infix_array[id] = '+';

			id = id + 1;
		}

		else if (infix_array[id] == '-')
		{
			if (id > 0 && infix_array[id - 1] != ')')
				i=isOperand(infix_array[id - 1]);


			if (i == 0 || id == 0)
				infix_array[id] = '#';
			else if (i == 1)
				infix_array[id] = '-';

			id = id + 1;
		}
		else
			id = id + 1;

		i = 2;

	}


	while (idx != N)
	{
		char s = infix_array[idx++];

		if (isOperand(s)) //피연산자 처리구문
		{
				write(s);
		}
		else if (s == '(')
			push(&S, s);

		else if (s == ')')
		{
			while (top(&S) != '(')
				write(pop(&S));

			pop(&S);
		}

		else if (s == ' ')
		{
			continue;
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
	char array[100];
	int num;

	scanf("%d", &num);
	getchar();

	for (int i = 0; i < num; i++)
	{
		gets(array);
		convert(array);
		printf("\n");
	}

	return 0;
}