#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void buildlist(int* A, int n);

void main()
{
	int* A;
	int n,k;
	int result;

	scanf("%d", &n);					//생일케이크 초 갯수
	scanf("%d", &k);					//생일케이크 촛불 끌 떄 건너뛸 촛불 수

	A = (int*)malloc(sizeof(int) * n);

	buildlist(A, n);					//생일케이크 초 세팅
	result = runSimulation(A, n, k);	//생일케이크 마지막 초 1개 남기 위해 건너뛰는 횟수

	printf("%d\n", result);
	
}

void buildlist(int* A, int n)
{
	for (int i = 0; i < n; i++)
		*(A + i) = i + 1;
}

int runSimulation(int* A, int n, int k)
{
	int r = 0;							//r = A배열의 인덱스
	int i, N = n;						//I 는 k개의 촛불을 건너뛸 때, 하나 건너뜀을 의미하는 변수, i=k이어야 k개의 촛불을 건너뛴 것
										//N은 처음 세팅한 촛불의 갯수

	while (n > 1)						//남아있는 촛불이 1개보다 많을 떄
	{
		i = 0;							//아직 건너뛴 촛불이 없어서 0으로 세팅
		while (i < k)					//아직 k개의 촛불을 건너뛴 게 아니라면
		{		
			r =(r + 1) % N;				//인덱스 1만큼 증가, 그리고 여기서 인덱스를 원래 촛불의 수로 나눈 나머지가 인덱스이어야 함, 원형배열이어서
			if (*(A + r) != 0)			//해당 인덱스의 값이 0이 아니라면
				i = i + 1;				//1개 건너뛰엇기 때문에 i = i+1
		}
		A[r] = 0;						//k의 촛불을 건너뛰어서 i=k가 되었다면 해당 인덱스 촛불=0으로 세팅
		n = n - 1;						//현재 켜져있는 촛불 수 1개 감소

		while (*(A + r) == 0)			//해당 인덱스 칸의 값이 0이면 촛불이 꺼진것이므로
			r = (r + 1) % N;			//끈 촛불 다음부터 다시 시작해야하므로 인덱스 1만큼 증가

		

	}
	return *(A + r);						//마지막으로 남은 촛불 반환

}