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

void list_first(list* p);		//����Ʈ �ʱ�ȭ �Լ�
node* createnode(int std_num, int book_num, int year, int month, int day);
void add_node(list* p, int std_num, int book_num, int year, int month, int day);
//void printt(list* p);
void print_node(list* p, int year, int month, int day, int student_num_last);

int main()
{
	list* lista;
	char op;							 //operation �� ������ ������ ����
	int student_num, book_num;
	int student_num_last;
	int year,month,day;					//day1=���� ���۳�, day2 = ���� �ݳ���

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
			break;					//�Է� ����
		}

	}
}

void list_first(list* p)		//����Ʈ �ʱ�ȭ �Լ�
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
void printt(list* p)		//���Ȯ���Լ�
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
	int day_num = 0;		//��¥ ���̸� ��� �� ������ ���� (= ������������ ���)
	int day_num_last = 0;	//�ݳ���¥ ���
	int day_result = 0;		//������� ~ �ݳ������� �Ⱓ
	int k;
	int chance = 0;




	///////////////////////////////////////////////////////////////////////////////////�ݳ���¥ ���



	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)		//�Էµ� �ݳ������� ������ ���
	{
		k = 1;

		while (k < month)		//1�� ~ �ش� �ݳ� ������
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

		day_num_last = day_num_last + day;			//���� �������� �ϵ� + �ش� ������ �� ��
	}



	else	//�Էµ� �ݳ������� ������ �ƴ� ���
	{
		k = 1;

		while (k < month)		//1�� - �ش� ���⳯¥���� ���� �� = ���� ��
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

		day_num_last = day_num_last + day;			//���� �������� �ϵ� + �ش� ������ �� ��
	}



	////////////////////////////////////////////////////////////////////////////////////////������� ���
	
	while (cur != NULL)	//����Ʈ�� ����� ������ ������ŭ
	{
	
			if (cur->student_num == student_num_last)
			{
				
				if (cur->year % 4 == 0 && cur->year % 100 != 0 || cur->year % 400 == 0)		//�Էµ� ���⿬���� ������ ���
				{
					k = 1;

					while (k < cur->month)		//1�� - �ش� ���⳯¥���� ���� �� = ���� ��
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

					if (cur->year < year)						//�ݳ� �⵵�� ���� �⵵���� ���� ���
					{
						day_result = (366 - day_num) + day_num_last;
					}
					else										//�ݳ� �⵵�� ���� �⵵�� ���� ��� ���
					{
						day_result = day_num_last - day_num;
					}

				}



				else	//�Էµ� ���⿬���� ������ �ƴ� ���
				{
					k = 1;

					while (k < cur->month)		//1�� - �ش� ���⳯¥���� ���� �� = ���� ��
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

					day_num = (day_num + cur->day);				//1�� ��ü �ϼ� - ���� ������ ��¥�� - �ش� ���� ��

						///////////////////////////////////////////////////////////////////////////////////////
					if (cur->year < year)						//�ݳ� �⵵�� ���� �⵵���� ���� ���
					{
						day_result = (365 - day_num) + day_num_last;
					}
					else										//�ݳ� �⵵�� ���� �⵵�� ���� ��� ���
					{
						day_result = day_num_last - day_num;
					}


				}

				///////////////////////////////////////////////////////////////////////////////////////


				if (day_result > 15)						//����Ⱓ�� 15�� ���� ���
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