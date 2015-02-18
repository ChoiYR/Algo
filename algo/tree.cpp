#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int key;
	struct _node *right;
	struct _node *left;
}node;

node *head;
node *tail = NULL;
void make(node *t);

void init_tree()
{
	head = (node*)malloc(sizeof(node));
	tail = (node*)malloc(sizeof(node));
	head->left	= tail;
	head->right	= tail;
	
	tail->left	= tail;
	tail->right	= tail;
}


/*	�Ѹ��� ���� Ÿ�� ���*/
//	1. �Ѹ��� ���� �湮�Ѵ�.
//	2. ���� ���� ���� �湮�Ѵ�
//	3. ������ ���� ���� �湮�Ѵ�.
void preorder_traverse(node *t)
{
	if(t != tail)
	{
//		visit(t);
		preorder_traverse(t->left);
		preorder_traverse(t->right);
	}
}

void preorder_input(node *t)
{
	if(t->left == tail && t->right == tail)
	{
		make(t);		
	}
}

void make(node *t

{
	static int key = 0;
	t = (node*)malloc(sizeof(node));
	t->key = key++;
	t->left = tail;
	t->right = tail;
}

void visit(node *t)
{
	static int key = 0;
	t		= (node*)malloc(sizeof(node));
	t->key	= key++;
	
}

int main()
{
	init_tree();
	preorder_input(head);

	return 0;
}