#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	int data;
	struct node* next;
}node;


struct Set
{
	int n;		//����� ���� ����
	int N;		//����� �ִ� ����
	struct node* head;
	struct node* tail;

	/////////////////////////////////////////////////////////////�⺻�Լ�
	int isEmpty()
	{
		if (n == 0)
			return 1;
		else
			return 0;
	}

	int size()
	{
		return n;	//������� �߰��� ����� ���� ����
	}

	int get(int r)
	{
		struct node* cur = head;
		for (int i = 1; i <  r; i++)
		{
			cur = cur->next;
		}
		
		return cur->data;
	}

	void set(int r, int e)
	{
		struct node* cur = head;

		for (int i = 1; i <= r; i++)
			cur = cur->next;

		cur->data = e;
	}


	void initialize(int k)
	{
		head = (node*)malloc(sizeof(node));

		head->next = NULL;	//�ʱ� ��Ȳ

		n = 0;
		N = k;

	}
	/////////////////////////////////////////////////////////////����Ʈ �Լ� ���� ����

	void invalidException()
	{
		printf("invalid rank\n");
	}



	void addLast(int e)
	{
		node* q = (node*)malloc(sizeof(node));

		q->data = e;
		q->next = NULL;

		tail->next = q;
		tail = q;
		
		n = n + 1;
	}

	void addFirst(int e)
	{

		node* q = (node*)malloc(sizeof(node));

		q->data = e;
		q->next = NULL;

		head = q;
		tail = q;			//head�� tail ��� ù ��带 ����Ŵ

		n = n + 1;

	}

	void addElem(int e)				//���տ��� ���Ҹ� �߰��� �� ����ϴ� �Լ� = ������ ����Ʈ�� addLast()�Լ��� ����
	{
		if (n == 0)
		{
			addFirst(e);
		}
		else
		{
			addLast(e);

		}
	}

	void add(int r, int e)
	{
		if (r <1 || r>N)
		{
			invalidException();
			return;
		}

		else
		{
			if (n == 0)
			{
				addFirst(e);
			}
			else
			{
				addLast(e);
			}
		}
		
	}

	int removeNode(node* p, node *q)	//�Լ��� ���� : ������ ���, �� ���
	{
		int e = p->data;

		q->next = p->next;

		free(p);
		p = NULL;		//Ȥ�� �𸣴ϱ� NULL�� ����

		return e;
	}

	int remove(int r)
	{
		int e;

		if (r <1 || r>N)
		{
			invalidException();
			return 0;
		}


		struct node* cur1 = head;
		struct node* cur2 = head;

		for (int i = 1; i < r; i++)	//������ ��ġ�� ���
			cur1 = cur1->next;

		for (int i = 1; i < r-1; i++)	//������ ��ġ�� ���� ���
			cur2 = cur2->next;

		e = removeNode(cur1, cur2);
		n = n - 1;
		return e;

	}

	void removeLast()
	{
		if (n < 1)
		{
			invalidException();
			return;
		}

		struct node* cur = head;	//���� ����ִ� ����� ������ ��� ����
		for (int i = 1; i < n - 1; i++)
			cur = cur->next;

		tail = cur;
		free(cur->next);

		n = n - 1;
		
	}

	void removeFirst()
	{
		if (n < 1)
		{
			invalidException();
			return;
		}

		struct node* cur = head;	//���� ����ִ� ����� ù��° ��� ����
		cur = cur->next;

		head = cur;
		
		free(head);	
	}

	void removeElem()						//���տ� ����ִ� ���� ���� �Լ� = removeFirst()�Լ��� ����
	{
		removeFirst();
	}

	void visit(int e)
	{
		printf("%d ", e);
	}

	void traverse()
	{
		node* cur = head;

		while (cur != NULL)
		{
			visit(cur->data);
			cur = cur->next;
		}

		printf("\n");
	}

	////////////////////////////////////////////������� ����Ʈ�� �Լ� ������ ����

	////////////////////////////////////////////�������� ���� �Լ� ����

	int member(int e)
	{
		if (n == 0)
			return 0;

		node* p = head;			//���� �ִ� ��带 �����Ѿ� �ϱ� ������ ������� ���� ��带 �����Ѿ� ��

		while (1)
		{
			int a = p->data;

			if (a < e)
				if (p->next == NULL)
					return e;
				else
					p = p->next;

			else if (a > e)
				return e;

			else					//�����Ѵٸ� -1 ��ȯ

				return -1;
		}
	}

	//�� ����(A)�� Set B�� �κ���������?
	void subset(Set B)
	{
		int temp;
		node* p = head;		//���� �ִ� ��带 �����Ѿ� �ϱ� ������ ������� ���� ��带 �����Ѿ� ��

		
		if ((B.N == 0) && (N !=0))		//B ������ �������̰� A ������ �������� �ƴ� ���
		{
			printf("%d\n", p->data);
			return;

		}

		
		else if((B.N !=0) && (N !=0))		//B ���հ� A ������ �������� �ƴ� ���
		{
			while (1)
			{
				if (B.member(p->data) == -1)
				{
					if (p->next == NULL)
					{
						printf("%d", 0);
						return;
					}
					else
					{
						p = p->next;
					}
				}

				else
				{
					temp = B.member(p->data);
					printf("%d\n", temp);
					return;
				}
			}

		}

		else 					//B ���հ� A ������ �������� ��� , B ������ �������� �ƴϰ� A ������ �������� ���
		{
			printf("%d\n", 0);
		}

	
	}
};



int main()
{
	int An, Bn;
	int n;
	Set A, B;



	scanf("%d", &An);
	A.initialize(An);

	for (int i = 0; i < An; i++)
	{
		scanf("%d", &n);
		A.addElem(n);
		
	}

	scanf("%d", &Bn);
	B.initialize(Bn);

	for (int i = 0; i < Bn; i++)
	{
		scanf("%d", &n);
		B.addElem(n);

	}

	A.subset(B);
}