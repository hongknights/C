#define _CRT_SECURE_NO_WARININGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct node
{
	int elem;
	struct node* next;
};

struct stack
{
	struct node* top;


	void initStack()
	{
		top = NULL;
		return;
	}

	struct node* getNode()
	{
		struct node* p = (struct node*)malloc(sizeof(struct node) * 1);
		p->elem = -1;
		p->next = NULL;
		return p;
	}

	void push(int e)
	{
		struct node* p = getNode();
		p->elem = e;
		p->next = top;
		top = p;
		return;
	}

	int isEmpty()
	{
		return (top == NULL);
	}

	void emptyStackException()
	{
		printf("StackException\n");
	}

	void putnode(struct node* p)
	{
		free(p);
		p = NULL;
	}

	int pop()
	{
		if (isEmpty())
		{
			emptyStackException();
			return -1;
		}

		int e = top->elem;
		struct node* p = top;
		top = top->next;
		putnode(p);
		return e;
	}

	void visit(int e)
	{
		printf("%c ", e);
	}


	void traverse()
	{
		struct node* p = top;

		while (p != NULL)
		{
			visit(p->elem);
			p = p->next;
		}
		printf("\n");
	}
};

int main()
{
	//push C, push B, push A, push X
	//traverse  ===>   X A B C

	struct stack S;
	S.initStack();

	S.push('C');
	S.push('B');
	S.push('A');
	S.push('X');


	S.traverse();

	return 0;
}