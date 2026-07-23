#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* pNext;
};
Node* initNode(int value)
{
	Node* p = new Node;
	p->data = value;
	p->pNext = NULL;
	return p;
}
struct Queue
{
	Node* front;
	Node* rear;
};
void initQueue(Queue& q)
{
	q.front = NULL;
	q.rear = NULL;
}
void addrear(Queue& q, Node* p)
{
	if (q.rear == NULL)
	{
		q.rear = p;
		q.front = p;
	}
	else
	{
		q.rear->pNext = p;
		q.rear = p;
	}
}
bool popHead(Queue &q)
{
	if (q.front == NULL)
		return false;
		Node* p = q.front;
		q.front = p->pNext;
		delete p;
		return true;
}
void printQueue(Queue q)
{
	Node* p = q.front; 
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->pNext;
	}
	cout << endl;
}
int main()
{
	Node* p1 = initNode(10);
	Node* p2 = initNode(20);
	Node* p3 = initNode(30);
	Queue q;
	initQueue(q);
	addrear(q, p1);
	addrear(q, p2);
	addrear(q, p3);
	printQueue(q);
}
