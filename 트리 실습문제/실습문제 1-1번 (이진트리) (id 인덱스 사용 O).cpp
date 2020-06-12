#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct treeNode
{
	int data;				//�ڽ��� ���� �뷮
	int id;
	treeNode* left;			//���� �ڽ� ��� ��ũ
	treeNode* right;		//������ �ڽ� ��� ��ũ

}treeNode;

treeNode* insertNode(int data, int id, treeNode* left, treeNode* right)
{
	//��� ����
	treeNode* v = (treeNode*)malloc(sizeof(treeNode) * 1);


	//��� �ʱ�ȭ
	v->data= data;
	v->id = id;
	v->left = left;
	v->right = right;

	return v;
}



//input : ����
//output : ��Ʈ����� �ּ�
treeNode* treeBuild()
{
	treeNode* F7 = insertNode(130,7, NULL, NULL);
	treeNode* F8 = insertNode(80, 8,NULL, NULL);
	treeNode* F6 = insertNode(120, 6,F7, F8);

	treeNode* F4 = insertNode(70, 4,NULL, NULL);
	treeNode* F5 = insertNode(90, 5, NULL, NULL);

	treeNode* F3 = insertNode(50,3, NULL, F6);
	treeNode* F2 = insertNode(30, 2,F4, F5);

	treeNode* F1 = insertNode(20, 1,F2, F3);


	return F1;
}


void visit(treeNode* v)
{
	printf("%d ", v->data);
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

		if (leftChild(v))
		{
			visit(leftChild(v));
		}

		if (rightChild(v))
		{
			visit(rightChild(v));

		}
	}
	else
	{
		printf("-1");
		return;
	}
}

treeNode* findID(treeNode* v, int id)
{
	

	if (v != NULL)
	{
		if (v->id == id)
			return v;		//�ش� ����� id�� ã�� id�� �����ϴٸ� �ش� ��� return

		treeNode* p = NULL;

		p = findID(leftChild(v), id);
		if (p != NULL)
			return p;		//p�� v�� �ɷ� return�� �ȴٸ�



		p = findID(rightChild(v), id);
		if (p != NULL) 
			return p;		//p�� v�� �ɷ� return�� �ȴٸ�

		
	}

	return NULL;
}

int main()
{
	treeNode* root = treeBuild();	//��Ʈ ��� �����Լ� �Ҵ�
	int id;							//ã���� �ϴ� ����ȣ
	treeNode* target;

	scanf("%d", &id);				//�Է�

	target = findID(root, id);
	
	binaryPreOrder(target);

	printf("\n");

	return 0;
}