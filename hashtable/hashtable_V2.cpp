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
const int size_h = 4;
struct Hashtable
{
	struct bucket
	{
		Node* pHead;
		Node* pTail;
	};
	bucket buckets[size_h];
};

typedef Hashtable HT;

void initHashtable(Hashtable& h)
{
	for (int i = 0; i < size_h; i++)
	{
		h.buckets[i].pHead = NULL;
		h.buckets[i].pTail = NULL;
	}
}
int hashfunction(int value)
{
	return value % size_h;
}
int hashfunction(Node* p)
{
	return p->data % size_h;
}
void add(Hashtable& h, Node* p)
{
	int x = hashfunction(p);
	if (h.buckets[x].pHead == NULL)
	{
		h.buckets[x].pHead = p;
		h.buckets[x].pTail = p;
	}
	else
	{
		p->pNext = h.buckets[x].pHead;
		h.buckets[x].pHead = p;
	}
}
void add(Hashtable& h, int value)
{
	int x = hashfunction(value);
	Node* p = initNode(value);
	if (h.buckets[x].pHead == NULL)
	{
		h.buckets[x].pHead = p;
		h.buckets[x].pTail = p;
	}
	else
	{
		p->pNext = h.buckets[x].pHead;
		h.buckets[x].pHead = p;
	}
}
void printHashtable(Hashtable h)
{
	for (int i = 0; i < size_h; i++)
	{
		cout << "\tbucket " << i << ":";
		for (Node* p = h.buckets[i].pHead; p != NULL; p = p->pNext)
		{
			cout << p->data << "\t";
		}
		cout << endl;
	}
}
int dataTable(Hashtable& h)
{

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
	return 10;
}
bool timvalue(HT h, int giatri)
{
	for (int i = 0; i < size_h; i++)
	{
		for (Node* p = h.buckets[i].pHead; p != NULL; p = p->pNext)
		{
			if (p->data == giatri)
				return true;
		}
	}
	return false;
}


int main()
{
	Hashtable h;
	initHashtable(h);

	cout << "Test: Tao du lieu: " << endl;
	int soluong = dataTable(h);
	cout << "ket qua : " << soluong << endl;

	cout << "Bang bam: " << endl;
	printHashtable(h);

	int giatri = 30;
	int n = timvalue(h, giatri);
	if (n == true)
	{
		cout << "da tim thay: " << giatri << endl;
	}
	else
	{
		cout << "khong tim thay" << endl;
	}
	printHashtable(h);
	return 0;

}