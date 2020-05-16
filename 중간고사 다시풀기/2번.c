#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char text[20];
	char* sub;
	int num2;
	int length;
	int j = 0;

	gets(text);

	length = strlen(text);
	sub = (char*)malloc(sizeof(char) * length);


	for (int i = 0; i < length; i++)
	{
		if (text[i] == '0')
		{
			sub[j] = '0';
			j++;
		}

		else if (text[i] == '1')
		{
			sub[j] = '1';
			j++;
		}
		else if (text[i] == '2')
		{
			sub[j] = '2';
			j++;
		}
		else if (text[i] == '3')
		{
			sub[j] = '3';
			j++;
		}
		else if (text[i] == '4')
		{
			sub[j] = '4';
			j++;
		}
		else if (text[i] == '5')
		{
			sub[j] = '5';
			j++;
		}
		else if (text[i] == '6')
		{
			sub[j] = '6';
			j++;
		}
		else if (text[i] == '7')
		{
			sub[j] = '7';
			j++;
		}
		else if (text[i] == '8')
		{
			sub[j] = '8';
			j++;
		}

		else if (text[i] == '9')
		{
			sub[j] = '9';
			j++;
		}
	}

	num2 = atoi(sub);

	for (int i = 1; i <= num2; i++)
	{
		if (num2 % i == 0)
			printf("%d ", i);
	}

	printf("\n");

	return 0;
		
}
