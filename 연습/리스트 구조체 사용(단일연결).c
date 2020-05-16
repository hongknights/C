#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//�����Է��� ũ�⸸ŭ �����Ҵ� �� �Է��� ���ڵ��� �������� ����Ʈ�� �����ϱ�


typedef struct node {
	char data;
	struct node* next;
} node;

typedef struct list {
	node* head;
	int numofnode;
	node* tail;

} list;

void listfirst(list* p);
node* createnode(char a);
void addnode(list* p, char a);
void printlist(list* p);

int main()
{
	char* num;
	int a;
	list* list1 = malloc(sizeof(list));

	listfirst(list1);

	scanf("%d", &a);
	num = (int*)malloc(sizeof(char) * a);


	for (int i = 0; i < a; i++)
	{
		scanf("%c", num + i);
		addnode(list1, (*num) + i);						//�߰��ϴ� �Լ� ȣ��
	}

	printlist(list1);

}

void listfirst(list *p)
{
	p->head = malloc(sizeof(node));
	p->tail = malloc(sizeof(node));

	p->head->next = p->tail;
	p->tail->next = NULL;
	p->numofnode = 0;
}

node* createnode(char a)
{
	node* newnode = malloc(sizeof(node));
	newnode->next = NULL;
	newnode->data = a;

	return newnode;
}

void addnode(list* p, char a)
{
	node *newnode = createnode(a);

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

void printlist(list* p)
{
	node* cur= p->head;

	for (int i = 0; i < p->numofnode; i++)
	{
		printf("%c ", cur->data);
		cur = cur->next;
	}

	printf("\n");

}
