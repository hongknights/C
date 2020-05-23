#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	struct node* prev;
	int data;
	struct node* next;
}node;


struct Set
{
	int n;		//����� ���� ����
	int N;		//����� �ִ� ����
	struct node* header;
	struct node* trailer;

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
		struct node* cur = header;
		for (int i = 1; i <= r; i++)
		{
			cur = cur->next;
		}

		return cur->data;
	}

	void set(int r, int e)
	{
		struct node* cur = header;

		for (int i = 1; i <= r; i++)
			cur = cur->next;

		cur->data = e;
	}


	void initialize(int k)
	{
		header = (node*)malloc(sizeof(node));
		trailer = (node*)malloc(sizeof(node));

		header->next = trailer;
		trailer->prev = header;			

		header->prev = NULL;
		trailer->next = NULL;			//�ʱ� ��Ȳ

		n = 0;
		N = k;

	}
	/////////////////////////////////////////////////////////////����Ʈ �Լ� ���� ����

	void invalidException()
	{
		printf("invalid rank\n");
	}

	void addNodeBefore(node* p, int e)
	{
		node* q = (node*)malloc(sizeof(node));

		q->data = e;
		q->prev = p->prev;
		q->next = p;

		(p->prev)->next = q;
		p->prev = q;
	}

	void addNodeAfter(node* p, int e)
	{
		node* q = (node*)malloc(sizeof(node));

		q->data = e;
		q->prev = p;
		q->next = p->next;

		(p->next)->prev = q;
		p->next = q;
	}


	void addLast(int e)
	{
		struct node* cur = trailer;

		addNodeBefore(cur, e);
		n = n + 1;
	}

	void addElem(int e)				//���տ��� ���Ҹ� �߰��� �� ����ϴ� �Լ� = ������ ����Ʈ�� addLast()�Լ��� ����
	{
		addLast(e);
	}

	void addFirst(int e)
	{
		struct node* cur = header;

		addNodeAfter(cur, e);
		n = n + 1;

	}
	void add(int r, int e)
	{
		if (r <1 || r>N)
		{
			invalidException();
			return;
		}

		struct node* cur = header;
		for (int i = 1; i <= r; i++)
			cur = cur->next;

		addNodeBefore(cur, e);
		n = n + 1;

	}

	int removeNode(node* p)
	{
		int e = p->data;

		(p->prev)->next = p->next;
		(p->next)->prev = p->prev;

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


		struct node* cur = header;
		for (int i = 1; i <= r; i++)
			cur = cur->next;

		e = removeNode(cur);
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

		remove(n);		//���� ����ִ� ����� ������ ��� ����
	}

	void removeFirst()
	{
		if (n < 1)
		{
			invalidException();
			return;
		}

		remove(1);		//���� ����ִ� ����� ù��° ��� ����
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
		node* cur = header->next;

		while (cur != trailer)
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

		node* p = header->next;			//���� �ִ� ��带 �����Ѿ� �ϱ� ������ ������� ���� ��带 �����Ѿ� ��

		while (1)
		{
			int a = p->data;

			if (a < e)
				if (p->next->next == NULL)
					return e;
				else
					p = p->next;

			else if (a > e)
				return e;

			else				//B�� ������ �����Ͱ� ����ִٸ� -1 ��ȯ
				return -1;
		}
	}


	//�� ����(A)�� Set B�� �κ���������?
	void subset(Set B)
	{
		node* p = header->next;		//���� �ִ� ��带 �����Ѿ� �ϱ� ������ ������� ���� ��带 �����Ѿ� ��
		int temp;


		if ((B.N == 0) && (N != 0))		//B ������ �������̰� A ������ �������� �ƴ� ���
		{
			printf("%d\n", p->data);
			return;

		}

		
		else if ((B.N != 0) && (N != 0))		//B ���հ� A ������ �������� �ƴ� ���
		{
			while (1)
			{
				if (B.member(p->data) == -1)	//B�� ������ �����Ͱ� ����ִٸ�
				{
					if ((p->next)->next == NULL)  //�� next->next == NULL ? : ���� �������� �ʴ� ����� trailer��尡 �����ϱ� ����
					{
						printf("%d\n", 0);
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