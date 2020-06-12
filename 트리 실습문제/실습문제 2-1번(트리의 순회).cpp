#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct treeNode
{
	int data;				//자신의 폴더 용량
	int id;
	struct treeNode* left;			//왼쪽 자식 노드 링크
	struct treeNode* right;		//오른쪽 자식 노드 링크

}treeNode;

treeNode* insertNode(int data, int id, treeNode* left, treeNode* right)
{
	//노드 생성
	treeNode* v = (treeNode*)malloc(sizeof(treeNode) * 1);


	//노드 초기화
	v->data = data;
	v->id = id;
	v->left = left;
	v->right = right;

	return v;
}



//input : 없고
//output : 루트노드의 주소
treeNode* treeBuild()
{
	treeNode* F7 = insertNode(130, 7, NULL, NULL);
	treeNode* F8 = insertNode(80, 8, NULL, NULL);
	treeNode* F6 = insertNode(120, 6, F7, F8);

	treeNode* F4 = insertNode(70, 4, NULL, NULL);
	treeNode* F5 = insertNode(90, 5, NULL, NULL);

	treeNode* F3 = insertNode(50, 3, NULL, F6);
	treeNode* F2 = insertNode(30, 2, F4, F5);

	treeNode* F1 = insertNode(20, 1, F2, F3);


	return F1;
}


void visit(treeNode* v)
{
	printf("%d ", v->data);
}


int isInternal(treeNode* v)
{
	if ((v->left != NULL) && (v->right != NULL))
		return 1;
	else
		return 0;

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
			binaryPreOrder(leftChild(v));
		}

		if (rightChild(v))
		{
			binaryPreOrder(rightChild(v));

		}
	}
	else
	{
		printf("-1");
		return;
	}
}

void binaryPostOrder(treeNode* v)
{
	if (v != NULL)
	{
		if (leftChild(v))
		{
			binaryPostOrder(leftChild(v));
		}

		if (rightChild(v))
		{
			binaryPostOrder(rightChild(v));
		}

		visit(v);
	}
	else
	{
		printf("-1");
		return;
	}
}

void binaryinOrder(treeNode* v)
{
	if (v != NULL)
	{
		if (leftChild(v))
		{
			binaryinOrder(leftChild(v));
		}

		visit(v);

		if (rightChild(v))
		{
			binaryinOrder(rightChild(v));
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
			return v;		//해당 노드의 id가 찾던 id와 동일하다면 해당 노드 return

		treeNode* p = NULL;

		p = findID(leftChild(v), id);
		if (p != NULL)
			return p;		//p에 v가 걸려 return이 된다면



		p = findID(rightChild(v), id);
		if (p != NULL)
			return p;		//p에 v가 걸려 return이 된다면


	}

	return NULL;
}

int main()
{
	treeNode* root = treeBuild();	//루트 노드 삽입함수 할당
	int find_way;					//탑색 방법 선택
	int id;							//찾고자 하는 노드번호
	treeNode* target;

	scanf("%d", &find_way);
	scanf("%d", &id);				//입력

	target = findID(root, id);

	if (find_way == 1)
		binaryPreOrder(target);

	else if (find_way == 2)
		binaryinOrder(target);

	else if (find_way == 3)
		binaryPostOrder(target);
	else
		printf("Can't find the way");

	printf("\n");

	return 0;
}