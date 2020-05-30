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
	int N; //스택의 최대 크기
	int n; //스택의 현재 크기
};

void initStack(struct stack* s, int N)
{
	s->top = NULL;
	s->N = N;	//스택의 최대 크기
	s->n = 0;	//스택의 현재 크기
	return;
}

struct node* getNode()
{
	struct node* p = (struct node*)malloc(sizeof(struct node) * 1);
	p->elem = -1;
	p->next = NULL;
	return p;
}

void emptyStackException()
{
	printf("Stack Empty\n");
}

void fullStackException()
{
	printf("Stack FULL\n");
}


void push(struct stack* s, char e)
{
	if (s->n < s->N)
	{
		struct node* p = getNode();
		p->elem = e;
		p->next = s->top;
		s->top = p;
		(s->n)++;
		return;
	}

	else
	{
		fullStackException();
		return;
	}
}

int isEmpty(struct stack* s)
{
	return (s->top == NULL);
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
	(s->n)--;
	putnode(p);
	return e;
}

void visit(int e)
{
	printf("%c", e);
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


void peek(struct stack* s)
{

	if (isEmpty(s)==1)
		emptyStackException();
	else
		printf("%c\n", s->top->elem);

}

void duplicate(struct stack* s)
{
	char data = pop(s);

	for (int i = 0; i < 2; i++)
	{
		if (s->n < s->N)
		{
			push(s, data);
		}
		else
			fullStackException();
	}
	
}

void upRotate(struct stack* s, int n)
{
	char* dataset = (char*)malloc(sizeof(char) * n); //스택에서의 데이터들을 모아두는 집합
	struct node* temp = s->top;

	if (n > s->n)
	{
		return;
	}

	else
	{
		for (int i = 0; i < n; i++)
		{
			dataset[i] = temp->elem;
			temp = temp->next;			//스택의 n번째까지의 elem들을 dataset에 저장
		}


		temp = s->top;

		for (int i = 0; i < n - 1; i++)
		{
			temp->elem = dataset[i + 1];
			temp = temp->next;				//1~n-1번쨰의 노드에 dataset의 data들을 저장
		}

		temp->elem = dataset[0];			//n번쨰 노드는 dataset의 [0]에 해당하는 data 저장

		return;
	}
}



void downRotate(struct stack* s, int n)
{
	char* dataset = (char*)malloc(sizeof(char) * n); //스택에서의 데이터들을 모아두는 집합
	struct node* temp = s->top;

	if (n > s->n)
	{
		return;
	}

	else
	{
		for (int i = 0; i < n; i++)
		{
			dataset[i] = temp->elem;
			temp = temp->next;			//스택의 n번째까지의 elem들을 dataset에 저장
		}


		temp = s->top;
		temp->elem = dataset[n - 1];			//첫번쨰 노드는 dataset의 [n-1]에 해당하는 data 저장

		for (int i = 0; i < n - 1; i++)
		{
			temp = temp->next;				//1~n-1번쨰의 노드에 dataset의 data들을 저장
			temp->elem = dataset[i];
		}

		return;
	}
}


int main()
{


	struct stack S;
	int N, M;				//N = Stack의 크기, M = 연산의 개수
	char sign[10];
	char data;
	int num;
	char sub;


	scanf("%d", &N);
	scanf("%d", &M);



	initStack(&S, N);


	for (int i = 0; i < M; i++)
	{	
		scanf("%s", sign);

		if (strcmp(sign, "POP") == 0)
		{
			sub=pop(&S);
			getchar();
		}

		else if (strcmp(sign, "PUSH") == 0)
		{
			getchar();
			scanf("%c", &data);
			push(&S, data);
			getchar();
		}

		else if (strcmp(sign, "PRINT") == 0)
		{
			traverse(&S);
			getchar();
		}
		else if (strcmp(sign, "UpR") == 0)
		{
			scanf("%d", &num);
			upRotate(&S, num);
			getchar();
		}

		else if (strcmp(sign, "DownR") == 0)
		{
			scanf("%d", &num);
			downRotate(&S, num);
			getchar();
		}

		else if (strcmp(sign, "PEEK") == 0)
		{
			peek(&S);
			getchar();
		}


		else if (strcmp(sign, "DUP") == 0)
		{
			duplicate(&S);
			getchar();
		}

	}

	return 0;
}