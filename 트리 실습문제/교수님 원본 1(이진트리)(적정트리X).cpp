#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct treeNode
{
	int elem;
	int id;
	treeNode* left;
	treeNode* right;
}treeNode;


treeNode* insertNode(int id, int elem, treeNode* left, treeNode* right)
{
	//��� ����
	treeNode* v = (treeNode*)malloc(sizeof(treeNode) * 1);
	

	//��� �ʱ�ȭ
	v->id = id;

	v->elem = elem;

	v->left = left;
	v->right = right;

	return v;
}



//input : ����
//output : ��Ʈ����� �ּ�
treeNode* treeBuild()
{
	treeNode* n7 = insertNode(7, 130, NULL, NULL);
	treeNode* n8 = insertNode(8, 80, NULL, NULL);
	treeNode* n6 = insertNode(6, 120, n7, n8);

	treeNode* n4 = insertNode(4, 70, NULL, NULL);
	treeNode* n5 = insertNode(5, 90, NULL, NULL);

	treeNode* n3 = insertNode(3, 50, NULL, n6);
	treeNode* n2 = insertNode(2, 30, n4, n5);

	treeNode* n1 = insertNode(1, 20, n2, n3);

	
	return n1;
}


void visit(treeNode* v)
{
	printf("%d ", v->elem);
}


int isInternal(treeNode* v)
{
	return { (v->left != NULL) && (v->right != NULL) };

}



treeNode* leftChild(treeNode* v)
{
	return v->left;
}

treeNode* rightChild(treeNode* v)
{
	return v->right;
}


//traverse
//preOrder / postOrder / inOrder

void binaryPreOrder(treeNode* v)
{
	if (v != NULL)
	{
		visit(v);
		binaryPreOrder(leftChild(v));
		binaryPreOrder(rightChild(v));
	}
}

void binaryPostOrder(treeNode* v)
{
	if (v != NULL)
	{
		binaryPostOrder(leftChild(v));
		binaryPostOrder(rightChild(v));
		visit(v);
	}
}

void binaryinOrder(treeNode* v)
{
	if (v != NULL)
	{
		binaryinOrder(leftChild(v));
		visit(v);
		binaryinOrder(rightChild(v));
	}
}

treeNode* findID(treeNode* v, int id)
{
	if (v != NULL)
	{
		if (v->id == id) return v;		//�ش� ����� id�� ã�� id�� �����ϴٸ� �ش� ��� return

		treeNode* p = NULL;

		p = findID(leftChild(v), id);
		if (p != NULL) return p;		//p�� v�� �ɷ� return�� �ȴٸ�

		p = findID(rightChild(v), id);
		if (p != NULL) return p;		//p�� v�� �ɷ� return�� �ȴٸ�
	}

	return NULL;	
}

int main()
{
	treeNode* root = treeBuild();
	
	binaryPostOrder(root);
	printf("\n");

	binaryinOrder(root);
	printf("\n");

	binaryPreOrder(root);
	printf("\n");

	return 1;
}