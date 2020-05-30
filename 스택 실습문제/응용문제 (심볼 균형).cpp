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

//////////////////////////////////////////////////////여기서부터 추가


int isOpenSymbol(char symbol)
{
	// {, (, [

	if ( symbol == '{' || symbol == '[' || symbol == '(')
		return 1;
	
	else
		return 0;

}



int isCloseSymbol(char symbol)
{
	// }, ], )

	if ( symbol == '}' || symbol == ']' || symbol ==')')
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
int isBalanced(char *array, int N)
{
	struct stack S;
	initStack(&S);

	int i = 0;
	while (i != N)
	{
		char symbol = array[i++];

		if ( isOpenSymbol(symbol) )
			push(&S, symbol);

		else if (isCloseSymbol(symbol))
		{
			if (isEmpty(&S))
				return 0;

			char symbol_open = pop(&S);

			if (!isCountpart(symbol, symbol_open))
				return 0;
		}

	}

	return isEmpty(&S);
}

int main()
{
	//char array[100] = "(3+40*(2+(30-7)*2133)";
	char array[100] = "(3+40*{2+(30-7}*2133)]";
	printf("%s\n", array);

	int ret = isBalanced(array, strlen(array));

	if (ret) printf("OK\n");
	else printf("Wrong\n");

	

	return 0;
} 