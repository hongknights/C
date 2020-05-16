#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//�����Է��� ũ�⸸ŭ �����Ҵ� �� �Է��� ���ڵ��� �������� ����Ʈ�� �����ϱ�


typedef struct node {
	int data;
	struct node* prev;
	struct node* next;
} node;

node* createnode(int a);
void addhead(node* head, int a);
void printlist(node* head);

int main()
{
	int* num;
	int a;
	node* head, * tail;

	scanf("%d", &a);
	num = (int*)malloc(sizeof(int) * a);

	head = (node*)malloc(sizeof(node));
	tail = (node*)malloc(sizeof(node));

	tail->data = NULL;
	head->next = tail;									//�ʱ����
	tail->prev = head;

	for (int i = 0; i < a; i++)
	{
		scanf("%d", num + i);
		addhead(head, (*num) + i);						//�߰��ϴ� �Լ� ȣ��
	}

	printlist(head);
}


node* createnode(int a)
{
	node* new;
	new = (node*)malloc(sizeof(node));
	new->data = a;
	new->next = NULL;
	new->prev = NULL;

	return new;
}

void addhead(node* head, int a)
{
	node* new = createnode(a);

	new->next = head->next;
	new->prev = head;
	head->next = new;
	head->next->prev = new;

}

void printlist(node* head)
{
	node* temp = head->next;

	while (temp->data != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}

	printf("\n");
}

