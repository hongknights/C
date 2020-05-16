#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//���߿��Ḯ��Ʈ �ٽ� ����
//���� , ���� , ����(������ ��� ������ not ���)

typedef struct node {
	struct node* prev;
	char data;
	struct node* next;
}node;


typedef struct list {
	struct node* head;
	struct node* tail;
	int numofdata;
} list;

void listfirst(list* p);
node* createnode(char a);
void insertnode(list* p, int r, char a);
void minusnode(list* p, int r);
void searchnode(list* p, int r);
void printnode(list* p);

int main()
{
	{
		int M, rank; //�ݺ��� ������ �� , �޼ҵ忡�� ����� ����
		list* p;
		char method, data; //a�� ������ �޼ҵ带 ����, d�� �׿� �ش��ϴ� ������ e

		p = malloc(sizeof(list));
		listfirst(p);

		scanf("%d", &M);//n���� ���� = n���� �ڷ� ...��? n���� �ڷḦ ����Ʈ�� �߰��� �� �ִ� n���� �� 
		getchar();


		for (int i = 0; i < M + 1; i++)								// ������ ���� ��ŭ �ݺ��� ����
		{
			scanf("%c", &method);

			if (method == 'A')
			{
				scanf("%d %c", &rank, &data);
				insertnode(p, rank, data);
				getchar();
			}
			else if (method == 'D')
			{
				scanf("%d", &rank);
				minusnode(p, rank);
				getchar();
			}
			else if (method == 'G')
			{
				scanf("%d", &rank);
				searchnode(p, rank);
				getchar();
			}
			else if (method == 'P')
			{
				printnode(p);
				getchar();
			}

		}
	}
}

void listfirst(list *p)
{
	p->head = malloc(sizeof(node));
	p->tail = malloc(sizeof(node));

	p->head->next = p->tail;
	p->tail->prev = p->head;  //�ʱ����

	p->numofdata = 0;
}

node* createnode(char a)
{
	node* newnode = malloc(sizeof(node));
	newnode->data = a;
	newnode->next = NULL;
	newnode->prev = NULL;

	return newnode;
}

void insertnode(list *p, int r, char a)
{
	node* cur = p->head;
	node* newnode = createnode(a);


		if (r <0 || r > (p->numofdata) + 1)
		{
			printf("invalid position\n");
		}

		else
		{
			for (int i = 1; i < r; i++)
			{
				cur = cur->next;			//������ġ�� �� ���
			}

			newnode->prev = cur;
			newnode->next = cur->next;
			(cur->next)->prev = newnode;
			cur->next = newnode;
			
		}
		p->numofdata++;
	
}

void minusnode(list* p, int r)
{
	node* cur1 = p->head;			//�����Ϸ��� ��ġ �������
	node* cur2 = p->head;			//�����Ϸ��� ��ġ ���


	if (r <0 || r > p->numofdata + 1)
	{
		printf("invalid position\n");
	}

	else
	{

		for (int i = 0; i < r-1; i++)
		{
			cur1 = cur1->next;
		}


		for (int i = 0; i < r; i++)
		{
			cur2 = cur2->next;			//�����Ϸ��� ���
		}

		cur1->next = cur2->next;
		cur2->next->prev = cur1;


		free(cur2);
		p->numofdata--;
	}
}


void searchnode(list *p, int r)
{
	node* cur = p->head;

	if (r <0 || r > p->numofdata + 1)
	{
		printf("invalid position\n");
	}

	else
	{

			for (int i = 0; i < r; i++)
			{
				cur = cur->next;
			}

		
			printf(" %c\n", cur->data);
	}
}

void printnode(list* p)
{
	node* cur = p->head->next;

	for (int i = 0; i < p->numofdata; i++)
	{
		printf("%c ", cur->data);
		cur = cur->next;
	}

	printf("\n");
}