#include<iostream>
#include <algorithm> // thêm thư viện này để dùng sort
using namespace std;

bool ls(int a[], int n, int x)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] == x) return true;
	}
	return false;
}

bool bs(int a[], int n, int x)
{
	int l = 0; int r = n - 1;
	while (l <= r)
	{
		int m = (l + r) / 2;
		if (a[m] == x)
		{
			return true;
		}
		else if (a[m] < x)
		{
			l = m + 1;
		}
		else r = m - 1;
	}
	return false;
}

bool binary_search(int a[], int l, int r, int x)
{
	if (l > r) return false;
	int m = (l + r) / 2;
	if (a[m] == x)
	{
		return true;
	}
	else if (a[m] < x)
	{
		return binary_search(a, m + 1, r, x);
	}
	else
		return binary_search(a, l, m - 1, x);
}

int vitridau(int a[], int n, int x)
{
	int l = 0; int r = n - 1;
	int res = -1;
	while (l <= r)
	{
		int m = (l + r) / 2;
		if (a[m] == x)
		{
			res = m;
			r = m - 1;
		}
		else if (a[m] > x)
		{
			r = m - 1;
		}
		else l = m + 1; 
	}
	return res; 
}

int vitricuoi(int a[], int n, int x)
{
	int l = 0; int r = n - 1;
	int res = -1;
	while (l <= r)
	{
		int m = (l + r) / 2;
		if (a[m] == x)
		{
			res = m;
			l = m + 1;
		}
		else if (a[m] > x)
		{
			r = m - 1; 
		}
		else l = m + 1; 
	}
	return res; 
}

int main()
{
	int n; cin >> n;
	int x; cin >> x;
	int a[1000];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	sort(a, a + n);

	if (binary_search(a, 0, n - 1, x))
		cout << "found \n";
	else cout << "NOT found\n";

	int l = vitridau(a, n, x);
	int r = vitricuoi(a, n, x);

	if (l != -1)
	{
		cout << r - l + 1 << endl;
	}
	else cout << "0" << endl;

	return 0;
}