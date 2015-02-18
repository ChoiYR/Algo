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


/*	뿌리를 먼저 타는 방법*/
//	1. 뿌리를 먼저 방문한다.
//	2. 왼쪽 작은 나무 방문한다
//	3. 오른쪽 작은 나무 방문한다.
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