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
	int n;		//노드의 현재 개수
	int N;		//노드의 최대 개수
	struct node* head;
	struct node* tail;

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

		head->next = NULL;	//초기 상황

		n = 0;
		N = k;

	}
	/////////////////////////////////////////////////////////////리스트 함수 구현 시작

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
		tail = q;			//head와 tail 모두 첫 노드를 가리킴

		n = n + 1;

	}

	void addElem(int e)				//집합에서 원소를 추가할 때 사용하는 함수 = 구현은 리스트의 addLast()함수와 동일
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

	int removeNode(node* p, node *q)	//함수의 인자 : 제거할 노드, 앞 노드
	{
		int e = p->data;

		q->next = p->next;

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


		struct node* cur1 = head;
		struct node* cur2 = head;

		for (int i = 1; i < r; i++)	//삭제할 위치의 노드
			cur1 = cur1->next;

		for (int i = 1; i < r-1; i++)	//삭제할 위치의 이전 노드
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

		struct node* cur = head;	//현재 들어있는 노드의 마지막 노드 삭제
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

		struct node* cur = head;	//현재 들어있는 노드의 첫번째 노드 삭제
		cur = cur->next;

		head = cur;
		
		free(head);	
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
		node* cur = head;

		while (cur != NULL)
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

		node* p = head;			//값이 있는 노드를 가리켜야 하기 때문에 헤드노드의 다음 노드를 가리켜야 함

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

			else					//존재한다면 -1 반환

				return -1;
		}
	}

	//본 집합(A)이 Set B의 부분집합인지?
	void subset(Set B)
	{
		int temp;
		node* p = head;		//값이 있는 노드를 가리켜야 하기 때문에 헤드노드의 다음 노드를 가리켜야 함

		
		if ((B.N == 0) && (N !=0))		//B 집합이 공집합이고 A 집합은 공집합이 아닐 경우
		{
			printf("%d\n", p->data);
			return;

		}

		
		else if((B.N !=0) && (N !=0))		//B 집합과 A 집합이 공집합이 아닐 경우
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