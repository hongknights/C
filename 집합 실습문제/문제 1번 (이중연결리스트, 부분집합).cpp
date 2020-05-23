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
	int n;		//노드의 현재 개수
	int N;		//노드의 최대 개수
	struct node* header;
	struct node* trailer;

	/////////////////////////////////////////////////////////////기본함수
	int isEmpty()
	{
		if (n == 0)
			return 1;
		else
			return 0;
	}

	int size()
	{
		return n;	//현재까지 추가된 노드의 개수 리턴
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
		trailer->next = NULL;			//초기 상황

		n = 0;
		N = k;

	}
	/////////////////////////////////////////////////////////////리스트 함수 구현 시작

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

	void addElem(int e)				//집합에서 원소를 추가할 때 사용하는 함수 = 구현은 리스트의 addLast()함수와 동일
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
		p = NULL;		//혹시 모르니깐 NULL을 대입

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

		remove(n);		//현재 들어있는 노드의 마지막 노드 삭제
	}

	void removeFirst()
	{
		if (n < 1)
		{
			invalidException();
			return;
		}

		remove(1);		//현재 들어있는 노드의 첫번째 노드 삭제
	}

	void removeElem()						//집합에 들어있는 원소 삭제 함수 = removeFirst()함수와 동일
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

	////////////////////////////////////////////여기까지 리스트의 함수 구현과 동일

	////////////////////////////////////////////이제부터 집합 함수 구현

	int member(int e)
	{
		if (n == 0)
			return 0;

		node* p = header->next;			//값이 있는 노드를 가리켜야 하기 때문에 헤드노드의 다음 노드를 가리켜야 함

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

			else				//B에 지정한 데이터가 들어있다면 -1 반환
				return -1;
		}
	}


	//본 집합(A)이 Set B의 부분집합인지?
	void subset(Set B)
	{
		node* p = header->next;		//값이 있는 노드를 가리켜야 하기 때문에 헤드노드의 다음 노드를 가리켜야 함
		int temp;


		if ((B.N == 0) && (N != 0))		//B 집합이 공집합이고 A 집합은 공집합이 아닐 경우
		{
			printf("%d\n", p->data);
			return;

		}

		
		else if ((B.N != 0) && (N != 0))		//B 집합과 A 집합이 공집합이 아닐 경우
		{
			while (1)
			{
				if (B.member(p->data) == -1)	//B에 지정한 데이터가 들어있다면
				{
					if ((p->next)->next == NULL)  //왜 next->next == NULL ? : 값이 존재하지 않는 노드인 trailer노드가 존재하기 때문
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

		else 					//B 집합과 A 집합이 공집합일 경우 , B 집합이 공집합이 아니고 A 집합은 공집합일 경우
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