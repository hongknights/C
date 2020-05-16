#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

	int n;
	int** matrix;
	int max = -1;									//1의 갯수가 같은 행이 여러 개일 경우 가장 작은 행번호를 고르기 위해서 -1 로 초기화
	int row = 0;

	scanf("%d", &n);

	matrix = (int**)malloc(sizeof(int*) * n);

	for (int i = 0; i < n; i++)
	{
		matrix[i] = (int*)malloc(sizeof(int) * n);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &matrix[i][j]);				//행렬 원소 입력
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = max+1; j < n; j++)				//행마다 그 전까지의 가장 컸던 열 번호+1 인덱스부터 탐색 시작
		{
			if (matrix[i][j] == 1)					//만약 그 전까지의 가장 컸던 행보다 1의 갯수가 많다면
			{
				max=j;								//최대 1의 갯수 저장
				row = i;							//해당 행 번호 조장
			}
		}
	}

	printf("%d\n", row);

	return 0;
}

//mostOnes(A,n)
//for i <- 0 to i <- n
	//for j <- -1 to j <- n
		//if (matrix[i][j] == 1)
			//max = j
			//row = i