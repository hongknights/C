#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

	int num; 
	int *length, *last;
	char** ch1, **ch2;
	int z;				//숫자만 골라서 저장할 배열에서 열을 나타내는 숫자로 사용
	int temp;

	scanf("%d", &num);							 //문자열 배열갯수 입력
	getchar();
	ch1 = (char**)malloc(sizeof(char*) * num);     //문자열배열의 갯수만큼 할당
	ch2 = (char**)malloc(sizeof(char*) * num);     //문자열배열의 갯수만큼 할당
	length = (int*)malloc(sizeof(int*) * num);
	last = (int*)malloc(sizeof(int*) * num);

	for (int i = 0; i < num; i++)
	{
		ch1[i] = (char*)malloc(sizeof(char) * 20); //문자열 길이 최대 20만큼 동적할당
		ch2[i] = (char*)malloc(sizeof(char) * 20); //문자열 길이 최대 20만큼 동적할당
	}

	for (int j = 0; j < num; j++)
	{
		gets(ch1[j]);								//문자열 입력
		length[j] = strlen(ch1[j]);					//각 문자열의 길이저장
	}

	for (int i = 0; i < num; i++)
	{
		z = 0;											//열 인덱스 초기화

		for (int j = 0; j < length[i]; j++)
		{
			if (ch1[i][j] >= 48 && ch1[i][j] <= 57)		//0~9까지의 아스키코드
			{
				ch2[i][z] = ch1[i][j];
				z++;									//다음 저장을 위해 열 인덱스 증가
			}
		}

	}


	for (int i = 0; i < num; i++)
	{
		last[i] = atoi(ch2[i]);
	}

	for (int j = 0; j < num; j++)
	{
		for (int i = j; i < num; i++)
		{
			if (last[i] > last[j])
			{
				temp = last[i];
				last[i] = last[j];
				last[j] = temp;
			}
		}
	}


	for (int i = 0; i < num; i++)
	{
		printf("%d\n", last[i]);
	}


}