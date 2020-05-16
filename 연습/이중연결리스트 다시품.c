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

node* createnode(char a);
void insertnode(node* head, int r, char a);
void addnode_already(node* p, node* newnode);
void minusnode(node* head, int r);
void searchnode(node* head, int a);
int countnode(node* head); 
void printnode(node *head);

int main()
{
	{
		int M, rank; //�ݺ��� ������ �� , �޼ҵ忡�� ����� ����
		node* head;
		node* tail;
		char method, data; //a�� ������ �޼ҵ带 ����, d�� �׿� �ش��ϴ� ������ e

		scanf("%d", &M);//n���� ���� = n���� �ڷ� ...��? n���� �ڷḦ ����Ʈ�� �߰��� �� �ִ� n���� �� 
		getchar();

		head = (node*)malloc(sizeof(node));
		tail = (node*)malloc(sizeof(node));

		head->next = tail;
		head->prev = NULL;											//������� ���ϳ�带 ����Ͽ� ����Ʈ �ʱ�ȭ

		tail->prev = head;											//�ʱ� ���� : HEAD <-> TAIL
		tail->next = NULL;

		for (int i = 0; i < M + 1; i++)								// ������ ���� ��ŭ �ݺ��� ����
		{
			scanf("%c", &method);

			if (method == 'A')
			{
				scanf("%d %c", &rank, &data);
				insertnode(head, rank, data);
				getchar();
			}
			else if (method == 'D')
			{
				scanf("%d", &rank);
				minusnode(head, rank);
				getchar();
			}
			else if (method == 'G')
			{
				scanf("%d", &rank);
				searchnode(head, rank);
				getchar();
			}
			else if (method == 'P')
			{
				printnode(head);
				getchar();
			}
		
		}
	}
	

}

node* createnode(char a)
{
	node* new;
	new = (node*)malloc(sizeof(node));

	new->data = a;
	new->next = NULL;
	new->prev = NULL;

	return new;
}


void insertnode(node* head, int r, char a)
{
	node* new = createnode(a);
	node* temp = head;
	int count = countnode(head);					//����Ʈ�� ����� ���� (������ ���� ��� ������ ����)

	if (r < 1 || r > count + 1)					//�� add�Լ��� ������ count+1�̻�? ���ϴ� �� ���� �ִ� ����+1������ ��� �Ǳ� ����
		printf("invalid position\n");

	else
	{
		for (int j = 1; j <= r; j++)
			temp = temp->next;							//rank��° ��尡 �ǰԲ� ��������ͷ� ��ȸ�� ��

		new->prev = temp->prev;
		new->next = temp->next;
		(temp->prev)->next = new;
		temp->prev = new;
	}
}


void addnode_already(node* p, node* newnode)		//���� : ������ �ڸ��� ���(�ڷ� ��ĭ �з��� ���). ������ ��ġ. ������ ���
{
	newnode->prev = p->prev;
	newnode->next = p;
	(p->prev)->next = newnode;
	p->prev = newnode;										//����
}


void minusnode(node* head, int r)
{
	node* temp = head;
	int count = countnode(head);


	if (r > count || r < 0)
	{
		printf("invalid number\n");
	}
	else
	{
		for (int i = 0; i < r; i++)
		{
			temp = temp->next;
		}


		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;

		free(temp);
	}

}

void searchnode(node* head, int a)
{
	node* temp = head;
	int count = countnode(head);

	for (int i = 0; i < count; i++)
	{
		if (temp->data == a)
			printf("%c\n", a);
		else
			temp = temp->next;
	}

}

void printnode(node *head)
{
	node* temp = head->next;
	int count = countnode(head);

	for (int i = 0; i < count; i++)
	{
		printf("%c", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int countnode(node* head)
{
	node* temp=head->next; //head��� ���� ����
	int sum=0;

	while (temp != NULL)
	{
		sum++;
		temp = temp->next;
	}

	return sum-1 ;			//tail��� �������� ����

}