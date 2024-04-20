#include<iostream>
#include<malloc.h>
#include<Windows.h>
#include<math.h>
#define Maxsize 30
using namespace std;
typedef char ElemType;
void gotoxy(int x, int y)
{
	COORD c;
	c.X = x - 1;
	c.Y = y - 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);//偏移光标位置
}
typedef struct TreeNode
{
	ElemType data;
	struct TreeNode* LChild, * RChild;
}*Tree;
typedef struct SqStack
{
	Tree data[Maxsize];
	int top;
}*Stack;
//创建栈
Stack InitStack()
{
	Stack S;
	S = (Stack)malloc(sizeof(SqStack));
	S->top = -1;
	return S;
}
//栈空
int StackEmpty(SqStack S)
{
	if (S.top == -1)return 1;
	else return 0;
}
//入栈
void Push(Stack S, Tree p)
{
	S->top++;
	S->data[S->top] = p;
}
//出栈
void Pop(Stack S, Tree* p)
{
	*p = S->data[S->top];
	S->top--;
}
Tree CreateTree()
{
	char ch;
	Tree n;
	scanf_s("%c", &ch, 1);
	if (ch == '#')n = NULL;
	else {
		n = (Tree)malloc(sizeof(TreeNode));
		n->data = ch;
		n->LChild = CreateTree();
		n->RChild = CreateTree();
	}
	return n;
}
//先序遍历二叉树
void PreOrder(Tree n)
{
	SqStack* S;
	S = InitStack();
	TreeNode* p;
	p = n;
	while (p || !StackEmpty(*S))
	{
		if (p)
		{
			printf("%c", p->data);
			Push(S, p);
			p = p->LChild;
		}
		else
		{
			Pop(S, &p);
			p = p->RChild;
		}
	}
}
//中序遍历二叉树
void InOrder(Tree n)
{
	SqStack* S;
	S = InitStack();
	TreeNode* p;
	p = n;
	while (p || !StackEmpty(*S))
	{
		if (p)
		{
			Push(S, p);
			p = p->LChild;
		}
		else
		{
			Pop(S, &p);
			printf("%c", p->data);
			p = p->RChild;
		}
	}
}
//后序遍历
void Postorder(Tree n)
{
	SqStack* S;
	S = InitStack();
	TreeNode* p;
	p = n;
	char tag[Maxsize] = { '0' };
	while (p || !StackEmpty(*S))
	{
		if (p)
		{
			Push(S, p);
			tag[S->top] = '0';//标志结点是否遍历右子树
			p = p->LChild;
		}
		else
		{
			while (tag[S->top] == '1') {
				Pop(S, &p);
				printf("%c", p->data);
			}
			if (S->top == -1) break;
			Pop(S, &p);
			Push(S, p);
			p = p->RChild;
			tag[S->top] = '1';
		}


	}
}
int GetHightOfTree(Tree n)
{
	int rh = 0, lh = 0;
	if (!n)return 0;
	else
	{
		lh = GetHightOfTree(n->LChild);
		rh = GetHightOfTree(n->RChild);
		return(lh > rh ? lh : rh) + 1;
	}
}
void DisplayBinTree(Tree n, int col, int row, int h)
{
	if (n)
	{
		gotoxy(col, row);
		printf("%c", n->data);
		DisplayBinTree(n->LChild, col - h, row + 1, h / 2);
		DisplayBinTree(n->RChild, col + h, row + 1, h / 2);
	}
}
void DisplayTree(Tree T)
{
	int k = 0;
	k = GetHightOfTree(T);
	DisplayBinTree(T, (int)pow(2, k - 1) * 2 + 1, 4, (int)pow(2, k - 1));
	printf("\n\n\n");
}
int main()
{
	Tree n;
	printf("请采用先序遍历输入:\n");
	n = CreateTree();
	printf("输出二叉树的树形结构");
	DisplayTree(n);
	printf("\n先序遍历输出\n");
	PreOrder(n);
	printf("\n中序遍历输出\n");
	InOrder(n);
	printf("\n后序遍历输出\n");
	Postorder(n);
	return 1;
}