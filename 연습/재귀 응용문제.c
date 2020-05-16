#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int product(int a, int  b); 
int modulo(int a, int b);
int quotient(int a, int b);

int main()
{
	int a, b;
	int p, m, q;
	scanf("%d %d", &a, &b);

	p = product(a, b);
	m = modulo(a, b);
	q = quotient(a, b);

	printf("%d %d %d\n", p, m, q);

}


int product(int a, int  b)
{

	if (a == 0)
		return 0;
	else
	{
		return b + product(a - 1, b);
	}
}

int modulo(int a, int b)
{

	if (a < b)
		return a;
	else
		modulo(a - b, b);
}

int quotient(int a, int b)
{

	if (a < b)
		return 0;
	else
	{
		return 1 + quotient(a - b, b);
	}
	
}