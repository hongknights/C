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
	if (s->top == NULL)
		return 1;
	else
		return 0;

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

//////////////////////////////////////////////////////여기서부터 추가


int isOpenSymbol(char symbol)
{
	// {, (, [

	if (symbol == '{' || symbol == '[' || symbol == '(')
		return 1;

	else
		return 0;

}



int isCloseSymbol(char symbol)
{
	// }, ], )

	if (symbol == '}' || symbol == ']' || symbol == ')')
		return 1;

	else
		return 0;

}

int isCountpart(char symbol, char symbol_open)
{
	if (symbol == '}' && symbol_open == '{')
		return 1;
	else if (symbol == ')' && symbol_open == '(')
		return 1;
	else if (symbol == ']' && symbol_open == '[')
		return 1;

	else
		return 0;
}

//array : 문자열의 주소
//N : 문자열의 크기
void isBalanced(char* array, int N)
{
	struct stack S;
	initStack(&S);

	int sum_set = 0;			//괄호의 세트가 맞는 경우의 세트의 개수
	int sum = 0;				//sum : 괄호의 전체 갯수
	char symbol_open;


	int i = 0;
	while (i != N)
	{
		char symbol = array[i];

		if (isOpenSymbol(symbol))
		{
			push(&S, symbol);
			sum = sum +1;
		}

		else if (isCloseSymbol(symbol))
		{
			if(isEmpty(&S) )		//여는 괄호가 스택에 있지 않을 경우
				sum = sum + 1;
				
				
			else						//여는 괄호가 스택에 있을 경우
			{
				symbol_open = pop(&S);

				if (isCountpart(symbol, symbol_open))
					sum_set = sum_set + 1;		//괄호의 세트 개수 저장

				sum = sum + 1;

			}
		}

		i++;

	}


	if (sum % 2 == 0)
	{
		if(sum_set * 2 == sum)
			printf("OK_%d\n", sum_set*2);

		else
			printf("Wrong_%d\n", sum);

	}
	else 
		printf("Wrong_%d\n", sum);

	return;
}

int main()
{
	
	char array[1000];

	gets(array);

	isBalanced(array, strlen(array));


	return 0;
}