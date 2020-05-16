#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//�����ϰ� 2��, 2�� ���� 
//10
//11 ������� ����
//���� x,y ���� 1,2�� ǥ��

typedef struct node {
	int data;
	struct node* next;
} node;

node* createnode(int a);
node* insertnode(node* tail1, node* tail2, int a); //tail1�� �� , tail2�� ��

int main()
{
	node* col[2];
	node* row[2];

	node* cols_head[2];
	node* cols_tail[2];

	node* rows_head[2];
	node* rows_tail[2];

	for (int i = 0; i < 2; i++)
	{
		col[i] = (node*)malloc(sizeof(node));
		row[i] = (node*)malloc(sizeof(node));

		cols_head[i] = (node*)malloc(sizeof(node));
		rows_head[i] = (node*)malloc(sizeof(node));

		cols_head[i]->next = cols_head[i];
		rows_head[i]->next = rows_head[i];


	}	//�ʱ�ȭ col,row�� �׳� ���ϸ���Ʈ cols_head�� rows_head�� �������Ḯ��Ʈ
		//�� ���� tail���� ����? ����: ������� �����ϱ� ����
		//rankó�� ��ġ�� �����ؼ� �����ϴ� ���� head�� ��ȸ�ϸ� �ذ��� ������ �̰Ŵ� rank�� ������ ������ x
		//������ �����迭�� ������ tail���̵� head�� tail ���� �ϳ��� �־ ���ϴ� ��ġ�� ���԰���, ������ ��� �� ��ġ�� ���׹��� why? ��� head�� �ٲ�ϱ�

	//������1 �ϴ� ���� �������� ���� ���� �� ���� �����ϴ°� ���ٰ� ������
	//���� : ��ȸ�� �ؾ���

	//������2 �׳� ���ڸ� 2�� �༭ �ٷ� �����ع���

	insertnode(cols_head[0], rows_head[0], 1);
	insertnode(cols_head[0], rows_head[1], 1);
	insertnode(cols_head[1], rows_head[1], 1);

	return 0;

}

node* createnode(int a)
{
	node* new = (node*)malloc(sizeof(node));
	new->data = a;
	new->next = NULL;

	return new;
}

node* insertnode(node* head1, node* head2 ,int a) //tail1�� �� , tail2�� ��
{
	node* temp1 = head1;
	node* temp2 = head2;
	node* newnode = createnode(a);
	

	temp1->next = newnode;
	newnode->next = temp1;

	temp2->next = newnode;
	newnode->next = temp2;
	
}