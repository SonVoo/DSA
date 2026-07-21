	#include<iostream>
	using namespace std;
	struct Node
	{
		int data;
		Node* pNext;
	};
	struct List
	{
		Node* pHead;
		Node* pTail;
	};
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
			l.pHead = p;
		}
	}
	void addTail(List& l, Node* p)
	{
		if (l.pHead == NULL)
		{
			l.pHead = p;
			l.pTail = p;
		}
		else
		{
			l.pTail->pNext = p;
			l.pTail = p;
		}
	} 
	bool popHead(List& l)
	{
		if (l.pHead == NULL)
			return false;
			Node* p = l.pHead;
			l.pHead = p->pNext;
			delete p;
			if (l.pHead == NULL)
				l.pTail = NULL;
			return true;
	}
	void printList(List l)
	{
		Node* p = l.pHead;
		while (p != NULL)
		{
			cout << p->data << "\t";
			p = p->pNext;
		}
	}
	bool timgiatri(List l, int value)
	{
		for (Node* p = l.pHead; p != NULL; p = p->pNext)
		{
			if (p->data = value)
				return true;
		}
		return false;
	}
	int timgiatrichan(List l)
	{
		int dem = 0;
		for (Node* p = l.pHead; p != NULL; p = p->pNext)
		{
			if (p->data % 2 == 0)
			{
				dem++;
			}
		}
		return dem;
	}
	int giatrimax(List l)
	{
		int m = l.pHead->data;
		for (Node* p = l.pHead->pNext; p != NULL; p = p->pNext)
		{
			if (p->data > m)
				m = p->data;
		}
		return m;
	}
	int tong(List l)
	{
		int t = 0;
		for (Node* p = l.pHead; p != NULL; p = p->pNext)
		{
			t += p->data;
		}
		return t;
	}
	int main()
	{
		List l = { NULL, NULL };
		Node* p =  new Node({ 10, NULL });
		Node* p1 = new Node({ 10, NULL });
		Node* p2 = new Node({ 25, NULL });
		Node* p3 = new Node({ 40, NULL });
		addTail(l, p1);

		int chan = timgiatrichan(l);
		cout << "So luong so chan: " << chan << endl;

		addTail(l, p1);
		addHead(l, p2);
		addTail(l, p3);
		int tinhtong = tong(l);
		cout << "Tong ds: " << tinhtong << endl;

		cout << "XOA: " << endl;
		popHead(l);

		cout << "Cac phan tu danh sach: ";
		printList(l);
	}



































