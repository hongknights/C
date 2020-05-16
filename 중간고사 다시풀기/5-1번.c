#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	int student_num;
	int book_num;
	int year, month, day;

	struct node* next;

}node;

typedef struct list
{
	struct node* head;
	struct node* tail;
	int numofnode;
} list;

void list_first(list* p);		//리스트 초기화 함수
node* createnode(int std_num, int book_num, int year, int month, int day);
void add_node(list* p, int std_num, int book_num, int year, int month, int day);
//void printt(list* p);
void print_node(list* p, int year, int month, int day, int student_num_last);

int main()
{
	list* lista;
	char op;							 //operation 즉 수행할 연산을 지정
	int student_num, book_num;
	int student_num_last;
	int year,month,day;					//day1=대출 시작날, day2 = 대출 반납날

	lista = (list*)malloc(sizeof(list));
	list_first(lista);


	while(1)
	{
		scanf("%c", &op);

		if (op == 'A')
		{
			scanf("%d %d %d-%d-%d", &student_num, &book_num, &year, &month, &day);
			getchar();
			add_node(lista, student_num, book_num, year, month, day);
		}

		else if (op == 'P')
		{
			scanf("%d-%d-%d %d", &year, &month, &day, &student_num_last);
			getchar();
			print_node(lista, year, month, day, student_num_last);
			//printt(lista);
		}

		else if (op == 'Q')
		{
			break;					//입력 종료
		}

	}
}

void list_first(list* p)		//리스트 초기화 함수
{
	p->head = (node*)malloc(sizeof(node));
	p->tail = (node*)malloc(sizeof(node));

	p->head = NULL;
	p->tail = NULL;
		
	p->numofnode = 0;
}

node* createnode(int std_num, int book_num , int year, int month,int day)
{
	node* newnode = (node*)malloc(sizeof(node));

	newnode->next = NULL;

	newnode->student_num = std_num;

	newnode->book_num = book_num;

	newnode->year = year;
	newnode->month = month;
	newnode->day = day;

	return newnode;
}

/*
void printt(list* p)		//노드확인함수
{
	node *temp = p->head;

	for (int i = 0; i < p->numofnode; i++)
	{
		printf("%d\n", temp->student_num);
		temp = temp->next;
	}

}
*/


void add_node(list* p, int std_num, int book_num, int year, int month, int day)
{
	node* newnode = createnode(std_num, book_num, year, month, day);
	node* cur = p->head;

	if (p->numofnode == 0)
	{
		p->head = newnode;
	}

	else
	{
		p->tail->next = newnode;
	}

	p->tail = newnode;

	p->numofnode++;
	
}



void print_node(list* p, int year, int month, int day, int student_num_last)
{
	node* cur = p->head;
	int day_num = 0;		//날짜 차이를 계산 후 저장할 변수 (= 몇일차이인지 계산)
	int day_num_last = 0;	//반납날짜 계산
	int day_result = 0;		//대출시작 ~ 반납까지의 기간
	int k;
	int chance = 0;




	///////////////////////////////////////////////////////////////////////////////////반납날짜 계산



	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)		//입력된 반납연도가 윤년인 경우
	{
		k = 1;

		while (k < month)		//1월 ~ 해당 반납 월까지
		{
			if (k == 1 || k == 3 || k == 5 || k == 7 || k == 8 || k == 10 || k == 12)
			{
				day_num_last = day_num_last + 31;

			}
			else if (k == 4 || k == 6 || k == 9 || k == 11)
			{
				day_num_last = day_num_last + 30;
			}
			else
			{
				day_num_last = day_num_last + 29;
			}
			k++;
		}

		day_num_last = day_num_last + day;			//지난 개월들의 일들 + 해당 개월의 일 수
	}



	else	//입력된 반납연도가 윤년이 아닌 경우
	{
		k = 1;

		while (k < month)		//1년 - 해당 대출날짜까지 지난 날 = 남은 날
		{
			if (k == 1 || k == 3 || k == 5 || k == 7 || k == 8 || k == 10 || k == 12)
			{
				day_num_last = day_num_last + 31;

			}
			else if (k == 4 || k == 6 || k == 9 || k == 11)
			{
				day_num_last = day_num_last + 30;
			}
			else
			{
				day_num_last = day_num_last + 28;
			}
			k++;
		}

		day_num_last = day_num_last + day;			//지난 개월들의 일들 + 해당 개월의 일 수
	}



	////////////////////////////////////////////////////////////////////////////////////////대출기한 계산
	
	while (cur != NULL)	//리스트에 저장된 원소의 갯수만큼
	{
	
			if (cur->student_num == student_num_last)
			{
				
				if (cur->year % 4 == 0 && cur->year % 100 != 0 || cur->year % 400 == 0)		//입력된 대출연도가 윤년인 경우
				{
					k = 1;

					while (k < cur->month)		//1년 - 해당 대출날짜까지 지난 날 = 남은 날
					{
						if (k == 1 || k == 3 || k == 5 || k == 7 || k == 8 || k == 10 || k == 12)
						{
							day_num = day_num + 31;

						}
						else if (k == 4 || k == 6 || k == 9 || k == 11)
						{
							day_num = day_num + 30;
						}
						else
						{
							day_num = day_num + 29;
						}

						k++;
					}

					day_num = (day_num + cur->day);

					///////////////////////////////////////////////////////////////////////////////////////

					if (cur->year < year)						//반납 년도가 대출 년도보다 뒤일 경우
					{
						day_result = (366 - day_num) + day_num_last;
					}
					else										//반납 년도가 대출 년도와 같을 경우 경우
					{
						day_result = day_num_last - day_num;
					}

				}



				else	//입력된 대출연도가 윤년이 아닌 경우
				{
					k = 1;

					while (k < cur->month)		//1년 - 해당 대출날짜까지 지난 날 = 남은 날
					{
						if (k == 1 || k == 3 || k == 5 || k == 7 || k == 8 || k == 10 || k == 12)
						{
							day_num = day_num + 31;

						}
						else if (k == 4 || k == 6 || k == 9 || k == 11)
						{
							day_num = day_num + 30;
						}
						else
						{
							day_num = day_num + 28;
						}
						k++;
					}

					day_num = (day_num + cur->day);				//1년 전체 일수 - 지난 개월의 날짜들 - 해당 월의 일

						///////////////////////////////////////////////////////////////////////////////////////
					if (cur->year < year)						//반납 년도가 대출 년도보다 뒤일 경우
					{
						day_result = (365 - day_num) + day_num_last;
					}
					else										//반납 년도가 대출 년도와 같을 경우 경우
					{
						day_result = day_num_last - day_num;
					}


				}

				///////////////////////////////////////////////////////////////////////////////////////


				if (day_result > 15)						//대출기간이 15일 넘을 경우
				{
					if (chance == 0)
					{
						printf("%d %d(%d) ", cur->student_num, cur->book_num, (day_result - 15) * 100);
						chance++;
					}
					else
						printf("%d(%d) ", cur->book_num, (day_result - 15) * 100);
				}

	

			}
			day_num = 0;
			cur = cur->next;
	
	}

	printf("\n");

	
}