#include<iostream>
#include<stack>
using namespace std;

struct Node
{
	int data;
	Node* pLeft;
	Node* pRight;
};

Node* initNode(int value)
{
	Node* p = new Node;
	p->data = value;
	p->pLeft = NULL;
	p->pRight = NULL;
}
struct Tree
{
	Node* pRoot;
};
Node* initTree(Tree& t)
{
	t.pRoot = NULL;
}
void add(Tree& t, Node* p)
{
	if (t.pRoot == NULL)
	{
		t.pRoot = p;
		return;
	}
	else
	{
		Node* pgoto = t.pRoot;
		Node* loca = NULL;
		while (pgoto != NULL)
		{
			loca = pgoto;
			if (pgoto->data < t.pRoot->data)
				pgoto = pgoto->pLeft;
			else if (pgoto->data > t.pRoot->data)
				pgoto = pgoto->pRight;
			else
				return;
		}
		if (p->data > loca->data)
			loca->pLeft = p;
		if (p->data < loca->data)
			loca->pRight = p;
	}
}
void add(Tree& t, int value)
{
	Node* p = initNode(value);
	add(t, p);
}
void printTree(Tree t)
{
	stack<Node*> s;
	Node* p = t.pRoot;
	while (p != NULL, s.empty() == false)
	{
		while (p != NULL)
		{
			s.push(p);
			p = p->pLeft;
		}
		p = s.top();
		s.pop();
		cout << p->data << endl;
		p = p->pRight;
	}

}
int main()
{
	Tree t;
	initTree(t);

	Node* p1 = initNode(10);
	Node* p2 = initNode(21);
	Node* p3 = initNode(22);
	Node* p3 = initNode(23);
	Node* p3 = initNode(32);
	Node* p3 = initNode(43);
	add(t, p1);
	add(t, p2);
	add(t, p2);
	add(t, 42);
}