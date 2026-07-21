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
struct bucket
{
	Node* pHead;
	Node* pTail;
};
void initbucket(bucket& bk)
{
	bk.pHead = NULL;
	bk.pTail = NULL;
}
// dinh nghia kieu hashtable
const int size_h = 5;
struct Hashtable
{
	bucket buckets[size_h];
};
void initHashtable(Hashtable& h)
{
	for (int i = 0; i < size_h; i++)
	{
		initbucket(h.buckets[i]);
	}
}
int Hashfunction(int value)
{
	return value % size_h;
}
int Hashfunction(Node* p)
{
	return p->data % size_h;
}
void push(bucket& bk, Node* p)
{
	if (bk.pHead == NULL)
	{
		bk.pHead = p;
		bk.pTail = p;
	}
	else
	{
		p->pNext = bk.pHead;
		bk.pHead = p;
	}
}
void add(Hashtable& h, Node* p)
{
	int vitri = Hashfunction(p);
	push(h.buckets[vitri], p);
}
void add(Hashtable& h, int value)
{
	int vitri = Hashfunction(value);
	push(h.buckets[vitri], initNode(value));
}
void printHashTable(Hashtable h)
{
	cout << "size of table: " << size_h << endl;
	for (int i = 0; i < size_h; i++)
	{
		cout << "Bucket [" << i << "]: ";
		for (Node* p = h.buckets[i].pHead; p != NULL; p = p->pNext)
		{
			cout << p->data << "\t";
		}
		cout << endl;
	}
}


int main()
{
	Hashtable h;
	initHashtable(h);

	Node* p1 = initNode(10);
	Node* p2 = initNode(20);
	Node* p3 = initNode(30);
	Node* p4 = initNode(40);

	add(h, p1);
	add(h, p2);
	add(h, p3);
	add(h, p4);

	add(h, 90);
	add(h, 31);
	printHashTable(h); 
}