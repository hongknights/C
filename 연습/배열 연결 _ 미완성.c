#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insert(int* m, int size, int rank, int num, int *n);

void main()
{
	int* m;
	int size, num, rank, n=0;

	scanf("%d", &size);										//배열 크기 지정

	m = (int*)malloc(sizeof(int) * size);					//배열크기만큼 동적할당

	for (int i = 0; i < size; i++)
	{
		scanf("%d %d", &rank, &num);							//삽입할 숫자와 위치 지정
		insert(m, size, rank, num, &n);
	}

	for (int i = 0; i < size; i++)
	{
		printf("%d", m[i]);
	}
	printf("\n");
}

void insert(int* m, int size, int rank, int num, int *n)
{

	if (rank >= size || rank < 0)
		printf("invalid position\n");

	else
	{
	
			for (int i = *n-1; i >= rank; i--)
			{
				
				m[i + 1] = m[i];
			}

			m[rank] = num;


			*n = *n + 1;
	}


}


void delete(int* m, int size, int rank, int *n)
{
	int e; 

	if (rank > *n - 1 || rank < 0)
		printf("invalid position\n");

	e = m[rank];

	{
		for (int i = rank+1; i <= *n-1; i++)
		{
			m[i-1] = m[i];
		}

		*n = *n - 1;
	}
}
