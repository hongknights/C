#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	int data;
	struct node* next;

}node;

typedef struct list
{
	struct node* head;
	struct node* tail;
	int numofnode;
} list;


void list_first(list* p);
node* createnode(int data);
void add_node(list* p, int data);
void print_node(list* p);

int main()
{
	int n;
	int* num;
	int data, temp;
	list* lista;

	lista = (list*)malloc(sizeof(list));
	list_first(lista);

	scanf("%d", &n);
	num = malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", num + i);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (*(num + i) > * (num + j))
			{
				temp = *(num + i);
				*(num + i) = *(num + j);
				*(num + j) = temp;
			}
		}
	}


	for (int i = 0; i < n; i++)
	{
		add_node(lista, *(num + i));
	}

	print_node(lista);

	return 0;

}

void list_first(list* p)		//리스트 초기화 함수
{
	p->head = (node*)malloc(sizeof(node));
	p->tail = (node*)malloc(sizeof(node));

	p->numofnode = 0;
}

node* createnode(int data)
{
	node* newnode = (node*)malloc(sizeof(node));

	newnode->next = NULL;

	newnode->data = data;

	return newnode;
}


void add_node(list* p,  int data)
{
	node* newnode = createnode(data);

	if (p->numofnode == 0)
	{
		p->head = newnode;
		p->tail = newnode;
	}

	else
	{
		p->tail->next = newnode;
		p->tail = newnode;
	}


	p->numofnode++;
}



void print_node(list* p)
{
	node* cur = p->head;


	for (int i = 1; i <= p->numofnode; i++)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}

	printf("\n");

}