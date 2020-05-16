#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	struct node* prev;
	char data;
	struct node* next;

}node;

typedef struct list
{
	struct node* head;
	struct node* tail;
	int numofnode;
} list;


void list_first(list* p);
node* createnode(char data);
void add_node(list* p, int rank, char data);
void delete_node(list* p, int rank);
void get_node(list* p, int rank);
void print_node(list* p);

int main()
{
	int num;
	int rank;
	char op, data;
	list *lista;

	lista = (list*)malloc(sizeof(list));
	list_first(lista);

	scanf("%d", &num);
	getchar();

	for (int i = 0; i < num; i++)
	{
		scanf("%c", &op);

		if (op == 'A')
		{
			scanf("%d %c", &rank, &data);
			getchar();
			add_node(lista, rank, data);
		}
		else if (op == 'D')
		{
			scanf("%d", &rank);
			getchar();
			delete_node(lista, rank);
		}
		else if (op == 'G')
		{
			scanf("%d", &rank);
			getchar();
			get_node(lista, rank);
		}
		else if (op == 'P')
		{
			getchar();
			print_node(lista);
		}


	}
}

void list_first(list *p)		//����Ʈ �ʱ�ȭ �Լ�
{
	p->head = (node *)malloc(sizeof(node));
	p->tail = (node*)malloc(sizeof(node));

	p->head->next = p->tail;
	p->tail->prev = p->head;

	p->numofnode = 0;
}

node *createnode(char data)
{
	node* newnode = (node*)malloc(sizeof(node));

	newnode->next = NULL;
	newnode->prev = NULL;

	newnode->data = data;

	return newnode;
}


void add_node(list* p, int rank, char data)
{
	node* newnode = createnode(data);
	node* cur = p->head;

	if (rank <0 || rank > p->numofnode + 1)
	{
		printf("invalid position\n");
	}
	else
	{
		for (int i = 0; i < rank; i++)
		{
			cur = cur->next;				//������ �ڸ��� �� ���
		}
		
		newnode->prev = cur->prev;
		newnode->next = cur;

		cur->prev->next = newnode;
		cur->prev = newnode;

		p->numofnode++;
	}

}


void delete_node(list* p, int rank)
{
	node* cur = p->head;

	if (rank <0 || rank > p->numofnode)
	{
		printf("invalid position\n");
	}
	else
	{
		for (int i = 0; i < rank; i++)
		{
			cur = cur->next;				//������ ��ġ�� ���
		}

		(cur->next)->prev = cur->prev;		//������ ����� ���� ���
		(cur->prev)->next = cur->next;		//������ ����� ���� ���

		free(cur);
		p->numofnode--;
		
	}
}

void get_node(list* p, int rank)
{
	node* cur = p->head;

	if (rank <0 || rank > p->numofnode)
	{
		printf("invalid position\n");
	}
	else
	{
		for (int i = 0; i < rank; i++)
		{
			cur = cur->next;			
		}

		printf("%c\n", cur->data);

	}
}

void print_node(list* p)
{
	node* cur = p->head;


	for (int i = 1; i <= p->numofnode; i++)
	{
		cur = cur->next;				
		printf("%c", cur->data);
	}

	printf("\n");
	
}