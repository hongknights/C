#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//이중연결리스트 다시 구현
//삽입 , 삭제 , 추출(있으면 출력 없으면 not 출력)

typedef struct node {
	char data;
	struct node* next;		//원형연결리스트
}node;


typedef struct list {
	struct node* head;
	int numofdata;
} list;

void listfirst(list* p);
node* createnode(char a);
void insertnode(list* p, list* q, char a);
void printnode(list* p);

int main()
{
	{
		list* A, *B ,*C, *z2, *x1, *y1,*z1;

		A = malloc(sizeof(list));
		B = malloc(sizeof(list));
		C = malloc(sizeof(list));

		z1 = malloc(sizeof(list));
		z2 = malloc(sizeof(list));
		x1 = malloc(sizeof(list));
		y1 = malloc(sizeof(list));

		listfirst(A);
		listfirst(B);
		listfirst(C);

		listfirst(z1);
		listfirst(z2);
		listfirst(x1);
		listfirst(y1);


		insertnode(A, x1, '1');
		insertnode(A, y1, '2');

		insertnode(B, z1, '3');
	
		insertnode(C, z2, '4');
		insertnode(C, y1, '5');
		insertnode(C, z1, '6');

		printnode(A);
		printnode(B);
		printnode(C);
		printnode(z2);
		printnode(x1);
		printnode(y1);
		printnode(z1);

		
	}
}

void listfirst(list* p)
{
	p->head = malloc(sizeof(node));

	p->head->data = NULL;
	p->head->next = p->head;			//원형연결리스트

	p->numofdata = 0;
}

node* createnode(char a)
{
	node* newnode = malloc(sizeof(node));
	newnode->data = a;
	newnode->next = newnode;

	return newnode;
}

void insertnode(list* p, list *q, char a)
{
	node* cur1 = p->head;
	node* cur2 = q->head;

	node* newnode = createnode(a);

	for (int i = 0; i < p->numofdata; i++)
		cur1 = cur1->next;

	newnode->next = cur1->next;
	cur1->next = newnode;

	for (int i = 0; i < q->numofdata; i++)
		cur2 = cur2->next;

	newnode->next = cur2->next;
	cur2->next = newnode;

	(p->numofdata)++;
	(q->numofdata)++;
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