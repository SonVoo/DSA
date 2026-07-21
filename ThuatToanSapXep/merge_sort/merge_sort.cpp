#include<iostream>
#include<vector>
using namespace std;

void merge(int a[], int l, int m, int r)
{
	vector<int> res;
	int i = l;
	int j = m + 1;

	while (i <= m && j <= r)
	{
		if (a[i] <= a[j])
		{
			res.push_back(a[i]);
			i++; 
		}
		else
		{
			res.push_back(a[j]);
			j++; 
		}
	}

	while (i <= m)
	{
		res.push_back(a[i]);
		i++; 
	}

	while (j <= r)
	{
		res.push_back(a[j]);
		j++; 
	}

	for (int k = 0; k < res.size(); k++)
	{
		a[l + k] = res[k];
	}

	for (int h = l; h <= r; h++)
	{
		cout << a[h] << " ";
	}
	cout << endl;
}

void mergesort(int a[], int l, int r)
{
	if (l >= r) return;
	int m = (l + r) / 2;
	mergesort(a, l, m);
	mergesort(a, m + 1, r);

	merge(a, l, m, r);
}

int main() {
	int a[] = { 6, 5, 12, 9, 10, 1 };
	int n = 6;

	cout << "mang ban dau: ";
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;

	mergesort(a, 0, n - 1);

	cout << "\nmang sau khi sap xep: ";
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;

	return 0;
}