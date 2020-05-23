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
		trailer->prev = header;			//초기 상황
		header->prev = NULL;
		trailer->next = NULL;

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
		printf(" %d", e);
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
					return 0;
				else
					p = p->next;

			else if (a > e)
				return 0;

			else
				return 1;
		}
	}

	//본 집합(A)이 Set B의 부분집합인지?
	int subset(Set B)
	{
		if (n == 0)			//공집합은 모든 집합의 부분집합이기 때문에 True, 1 반환
			return 1;

		node* p = header->next;		//값이 있는 노드를 가리켜야 하기 때문에 헤드노드의 다음 노드를 가리켜야 함

		while (1)
		{
			if (B.member(p->data) == 1)
			{
				if ((p->next)->next == NULL)  //왜 next->next == NULL ? : 값이 존재하지 않는 노드인 trailer노드가 존재하기 때문
					return 1;
				else
					p = p->next;
			}

			else
				return 0;
		}
	}
};

Set my_union(Set A, Set B)				//합집합 함수
{
	/////의사코드 1,
	Set C;
	C.initialize(A.N + B.N);

	/////의사코드 2.
	if (A.N != 0 || B.N != 0)
	{
		while (!A.isEmpty() & !B.isEmpty())
		{
			int a = A.get(1);
			int b = B.get(1);

			if (a < b)
			{
				C.addLast(a);
				A.removeFirst();
			}

			else if (a > b)
			{
				C.addLast(b);
				B.removeFirst();
			}
			else
			{
				C.addLast(a);
				A.removeFirst();
				B.removeFirst();

			}
		}

		//////의사코드 3.

		while (!A.isEmpty())
		{
			int a = A.get(1);

			C.addLast(a);
			A.removeFirst();
		}

		while (!B.isEmpty())
		{
			int b = B.get(1);

			C.addLast(b);
			B.removeFirst();
		}
	}

	else
	{
		C.addLast(0);
	}

	return C;

}


Set my_intersect(Set A, Set B)
{
	//1.
	Set C;
	C.initialize(A.N + B.N);


	//2.
	if ((A.N != 0) && (B.N != 0))
	{
		while (!A.isEmpty() & !B.isEmpty())
		{
			int a = A.get(1);
			int b = B.get(1);

			if (a < b)
			{
				A.removeFirst();
			}

			else if (a > b)
			{
				B.removeFirst();
			}
			else
			{
				C.addLast(a);
				A.removeFirst();
				B.removeFirst();

			}
		}

		//3.

		while (!A.isEmpty())
		{
			A.removeFirst();
		}

		while (!B.isEmpty())
		{
			B.removeFirst();
		}
	}

	else
	{
		C.addLast(0);
	}

	return C;

}


int main()
{
	int An, Bn;
	int n;
	Set A1, B1;
	Set A2, B2;
	Set U, I;



	scanf("%d", &An);
	A1.initialize(An);
	A2.initialize(An);

	for (int i = 0; i < An; i++)
	{
		scanf("%d", &n);
		A1.addElem(n);
		A2.addElem(n);

	}



	scanf("%d", &Bn);
	B1.initialize(Bn);
	B2.initialize(Bn);

	for (int i = 0; i < Bn; i++)
	{
		scanf("%d", &n);
		B1.addElem(n);
		B2.addElem(n);

	}



	U = my_union(A2, B2);
	U.traverse();

	I = my_intersect(A1, B1);
	I.traverse();
}