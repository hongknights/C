#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//�����Է��� ũ�⸸ŭ �����Ҵ� �� �Է��� ���ڵ��� �������� ����Ʈ�� �����ϱ�


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
	head->next = tail;									//�ʱ����

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