#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


typedef struct node {
	struct node* prev;
	int data;
	struct node* next;
} node;


typedef struct list {
	node* head;
	node* tail;
	int numofdata;
} list;

void listfirst(list* p);
node* createnode(int a);
void addtail(list* p, int a);
void printlist(list* q);

int main()
{
	int* num;
	int a;
	list* list1;

	scanf("%d", &a);
	num = (int*)malloc(sizeof(int) * a);

	list1 = malloc(sizeof(list));

	listfirst(list1);

	for (int i = 0; i < a; i++)
	{
		scanf("%d", num + i);
		addtail(list1, *(num + i));						//추가하는 함수 호출
	}

	printlist(list1);

	return 0;
}

void listfirst(list* p)
{

	p->head = malloc(sizeof(node));
	p->tail= malloc(sizeof(node));

	p->head->next = p->tail;
	p->tail->prev = p->head;

	p->numofdata = 0;
}


node* createnode(int a)
{
	node* new;
	new = (node*)malloc(sizeof(node));
	new->data = a;
	new->prev = NULL;
	new->next = NULL;

	return new;
}

void addtail(list* p, int a)
{	
	node* cur1 = p->head;
	node* cur2 = p->tail;

	node* newnode = createnode(a);
	
	newnode->prev = cur2->prev;
	newnode->next = cur2;
	cur2->prev->next = newnode;
	cur2->prev = newnode;
	
	p->numofdata++;
}

void printlist(list* p)
{
	node* cur = p->head->next;

	for (int i = 0; i < p->numofdata; i++)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}

	printf("\n");

}