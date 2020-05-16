#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//연결리스트 다시 구현
//삽입 , 삭제 , 추출(있으면 출력 없으면 not 출력)

typedef struct node {
	char name[2];
	char elem;
	struct node* next;		//원형연결리스트
}node;


typedef struct list {
	struct node* head;
	struct node* tail;
	int numofdata;
} list;

void listfirst(list* p);
node* createnode(char *name, char elem);
void insertnode(list* p, char *name, char elem);
void printnode(list* p);

int main()
{
	list* A = malloc(sizeof(list));

	listfirst(A);

	insertnode(A, "z1", 'Z');
	insertnode(A, "x2", 'X');
	insertnode(A, "z3", 'Z');

	printnode(A);

	return 0;
}

void listfirst(list* p)
{
	p->head = malloc(sizeof(node));
	p->tail = malloc(sizeof(node));


	p->head->next = p->tail;
	p->tail->next = NULL;

	p->numofdata = 0;

}

node* createnode(char* name, char elem)
{
	node* newnode = malloc(sizeof(node));
	strcpy(newnode->name ,name);
	newnode->elem = elem;

	newnode->next = NULL;

}

void insertnode(list* p, char* name, char elem)
{
	node* cur = p->head;
	node* newnode = createnode(name, elem);


	for (int i = 0; i < p->numofdata; i++)
	{
		cur = cur->next;
	}

		cur->next = newnode;
		p->tail = newnode;

		p->numofdata++;

}

void printnode(list* p)
{
	node* cur = p->head->next;

	for (int i = 0; i < p->numofdata; i++)
	{
		puts(cur->name);
		printf(" %c\n", cur->elem);

		cur = cur->next;
	}
	printf("\n");
}