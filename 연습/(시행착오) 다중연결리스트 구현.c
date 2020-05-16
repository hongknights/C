#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//간단하게 2개, 2개 구현 
//10
//11 모양으로 구현
//열은 x,y 행은 1,2를 표현

typedef struct node {
	int data;
	struct node* next;
} node;

node* createnode(int a);
node* insertnode(node* tail1, node* tail2, int a); //tail1은 열 , tail2는 행

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


	}	//초기화 col,row는 그냥 단일리스트 cols_head와 rows_head는 원형연결리스트
		//왜 굳이 tail까지 선언? 이유: 순서대로 저장하기 떄문
		//rank처럼 위치를 지정해서 삽입하는 경우는 head로 순회하면 해결이 되지만 이거는 rank로 지정한 연습이 x
		//하지만 원형배열의 장점은 tail없이도 head나 tail 둘중 하나만 있어도 원하는 위치에 삽입가능, 하지만 출력 시 위치가 뒤죽박죽 why? 계속 head가 바뀌니깐

	//설계방법1 일단 열을 기준으로 만든 다음 그 다음 연결하는게 좋다고 생각함
	//단점 : 순회를 해야함

	//설계방법2 그냥 인자를 2개 줘서 바로 연결해버림

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

node* insertnode(node* head1, node* head2 ,int a) //tail1은 열 , tail2는 행
{
	node* temp1 = head1;
	node* temp2 = head2;
	node* newnode = createnode(a);
	

	temp1->next = newnode;
	newnode->next = temp1;

	temp2->next = newnode;
	newnode->next = temp2;
	
}