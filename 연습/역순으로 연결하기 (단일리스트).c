#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//숫자입력한 크기만큼 동적할당 후 입력한 숫자들을 역순으로 리스트에 연결하기


typedef struct node {
	int data;
	struct node *next;
} node;

node* createnode(int a);
void addhead(node* head, int a);
void printlist(node* head);

int main()
{
	int* num;
	int a;
	node *head, *tail;

	scanf("%d", &a);
	num = (int*)malloc(sizeof(int) * a);

	head = (node*)malloc(sizeof(node));
	tail = (node*)malloc(sizeof(node));

	tail = NULL;
	head->next = tail;									//초기상태

	for (int i = 0; i < a; i++)
	{
		scanf("%d", num + i);
		addhead(head, (*num) + i);						//추가하는 함수 호출
	}

	printlist(head);

}

node* createnode(int a)
{
	node* new;
	new = (node*)malloc(sizeof(node));
	new->data = a;
	new->next = NULL;

	return new;
}

void addhead(node* head, int a)
{
	node* new = createnode(a);

	new->next = head->next;
	head->next = new;
	
}

void printlist(node* head)
{
	node* temp = head->next;

	while (temp!=NULL)
	{
		printf("%d\n", temp->data);
		temp = temp->next;
	}
}