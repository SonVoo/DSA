#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node* pPre;
	Node* pNext;
};
Node* initNode(int value)
{
	Node* p = new Node;
	p->data = value;
	p->pPre = NULL;
	p->pNext = NULL;
	return p;
}
struct List
{
	Node* pHead;
	Node* pTail;
};
void initList(List& l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}
void addHead(List& l, Node* p)
{
	if (l.pHead == NULL)
	{
		l.pHead = p;
		l.pTail = p;
	}
	else
	{
		p->pNext = l.pHead;
		l.pHead->pPre = p;
		l.pHead = p;
	}
}
void addTail(List& l, Node* p)
{
	if (l.pTail == NULL)
	{
		l.pHead = p;
		l.pTail = p;
	}
	else
	{
		l.pTail->pNext = p;
		p->pPre = l.pTail;
		l.pTail = p;
	}
}
void printList(List l)
{;
	 for (Node* p = l.pHead; p != NULL; p = p->pNext)
	 {
		 cout << p->data << "\t";
	 } cout << endl;
	for (Node* p = l.pTail; p != NULL; p = p->pPre)
	{
		cout << p->data << "\t";
	}
}
int main()
{
	Node* p1 = initNode(10);
	Node* p2 = initNode(20);
	Node* p3 = initNode(30);

	List l;
	initList(l);
	addHead(l, p2);
	addTail(l, p3);
	printList(l);


}