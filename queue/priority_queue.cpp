#include<iostream>
#include<queue>
using namespace std;

//int main()
//{
//	//priority_queue<int> pq;
//	priority_queue<int, vector<int>, greater<int>>pq;
//
//	pq.push(1);
//	pq.push(2);	
//	pq.push(44);
//	pq.push(6);
//	pq.push(8);
//	pq.push(10);
//	cout << pq.top() << " ";
//}

//bai toan noi day
int main()
{
	int t;
	if (!(cin >> t)) return 0; 

	while (t--)
	{
		int n;
		cin >> n;
		priority_queue<int, vector<int>, greater<int>> pq;

		for (int i = 0; i < n; i++) 
		{
			int x;
			cin >> x;
			pq.push(x);
		}

		long long kq = 0;
		while (pq.size() > 1)
		{
			long long top1 = pq.top(); pq.pop(); 
			long long top2 = pq.top(); pq.pop(); 

			kq += top1 + top2; 
			pq.push(top1 + top2); 
		}

		cout << kq << endl;
	}

	return 0;
}