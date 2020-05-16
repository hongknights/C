#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//이중연결리스트 다시 구현
//삽입 , 삭제 , 추출(있으면 출력 없으면 not 출력)

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
		int M, rank; //반복할 연산의 수 , 메소드에서 사용할 순위
		node* head;
		node* tail;
		char method, data; //a는 수행할 메소드를 결정, d는 그에 해당하는 데이터 e

		scanf("%d", &M);//n개의 연산 = n개의 자료 ...왜? n개의 자료를 리스트에 추가할 시 최대 n개가 됨 
		getchar();

		head = (node*)malloc(sizeof(node));
		tail = (node*)malloc(sizeof(node));

		head->next = tail;
		head->prev = NULL;											//헤더노드와 테일노드를 사용하여 리스트 초기화

		tail->prev = head;											//초기 설정 : HEAD <-> TAIL
		tail->next = NULL;

		for (int i = 0; i < M + 1; i++)								// 연산의 갯수 만큼 반복문 실행
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
	int count = countnode(head);					//리스트내 노드의 개수 (헤드노드와 테일 노드 제외한 개수)

	if (r < 1 || r > count + 1)					//왜 add함수만 범위가 count+1이상? 더하는 건 현재 있는 갯수+1까지만 허용 되기 때문
		printf("invalid position\n");

	else
	{
		for (int j = 1; j <= r; j++)
			temp = temp->next;							//rank번째 노드가 되게끔 헤드포인터로 순회를 함

		new->prev = temp->prev;
		new->next = temp->next;
		(temp->prev)->next = new;
		temp->prev = new;
	}
}


void addnode_already(node* p, node* newnode)		//인자 : 삽입할 자리의 노드(뒤로 한칸 밀려날 노드). 삽입할 위치. 삽입할 노드
{
	newnode->prev = p->prev;
	newnode->next = p;
	(p->prev)->next = newnode;
	p->prev = newnode;										//삽입
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
	node* temp=head->next; //head노드 갯수 제외
	int sum=0;

	while (temp != NULL)
	{
		sum++;
		temp = temp->next;
	}

	return sum-1 ;			//tail노드 갯수에서 제외

}