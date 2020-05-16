#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char V[8] = { 0 };
	
	V[1] = 'E';
	V[2] = 'S';
	V[3] = 'P';
	V[4] = 'N';

}
int size(char* V)
{
	int f, l;
	int N=0;

	for (int i = 0; *(V + i) != NULL; i++)
	{
		if (*(V + i) != 0)
		{
			f = i;
			break;
		}
	}

	for (int i = 0; *(V + i) != NULL; i++)
	{
		if (*(V + i) != 0)
		{
			l = i;
		}
	}

	for (int i = 0; *(V + i) != NULL; i++)
	{
		N++;
	}

	return (N - f + l + 1) % N;
}

char get(int r, char *V)
{
	if (r < 0 || r >= size(V))
		printf("invalid position\n");
	
	return V[()]
}


void addit(char *V ,int r, int e, int N) //필요한 변수, f, l , size, *V, e, r, N
{
	int n = size(V);

	if (n = N - 1)
		printf("invalid position\n");
	if (r<0 || r>n)
		printf("invalid position\n");

	if (r < n / 2)
	{
		for (int i = f; i < (f + r - 1) % N; i++)
		{
			V[(i - 1) % N] = V[i];
		}
		V[(f + r - 1) % N] = e;
		f = (f - l) % N;
	}
	else
	{
		for (int i = l; i < (f + r) % N; i--)
		{
			V[(i + 1) % N] = V[i];
		}
		V[(f + r) % N] = e;
		l = (l - l) % N;
	}
}

void remove(char* V, int r, int N)
{
	int n = size(V);

	if (n = 0)
		printf("invalid position\n");
	if (r < 0 || r >= n)
		printf("invalid position\n");

	if (r < n / 2)
	{
		for (int i = (f + r - 1) % N; i <= f; i--)
			V[(i + 1) % N] = V[i];
		f = (f + 1) % N;
	}
	else
	{
		for (int i = (f + r + 1) % N; i <= l; i++)
			V[(i - 1) % N] = V[i];
		l = (l - 1) % N;

	}
}