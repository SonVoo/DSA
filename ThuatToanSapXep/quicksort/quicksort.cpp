#include<iostream>
using namespace std;

int partition(int a[], int l, int r)
{
	int pivot = a[r];
	int i = l - 1;
	for (int j = l; j < r; j++)
	{
		if (a[j] < pivot)
		{
			i++;
			swap(a[i], a[j]);
		}
	}
	i++;
	swap(a[i], a[r]);
	return i;
}
void quicksort_lomuto(int a[], int l, int r)
{
	if (l >= r) return;
	int p = partition(a, l, r);
	quicksort_lomuto(a, l, p - 1);
	quicksort_lomuto(a, p + 1, r);
}

int partition2(int a[], int l, int r)
{
	int pivot = a[r];
	int i = l - 1; 
	int j = r + 1;
	while (true) {
		do {
			i++;
		} while (a[i] < pivot);

		do {
			j--;
		} while (a[j] > pivot);

		if (i >= j) return j;

		swap(a[i], a[j]);
	}
}

void quicksort_hoare(int a[], int l, int r) {
	if (l >= r) return;
	int p = partition2(a, l, r);
	quicksort_hoare(a, l, p);
	quicksort_hoare(a, p + 1, r);
}
int main()
{
	int a[1000]; int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	quicksort_hoare(a, 0, n - 1);
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}