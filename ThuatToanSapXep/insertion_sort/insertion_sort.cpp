#include<iostream>

using namespace std;

void insertionSort(int a[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int temp = a[i];
		int j = i - 1; 
		for (; j >= 0; j--)
		{
			if (a[j] < temp)
				break;
			a[j + 1] = a[j];
		}
		a[j + 1] = temp;
	}
}
void print(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
int main()
{
	int a[100] = { 18, 65, 34, 27, 89 };
	int n = 5;
	print(a, n);
	insertionSort(a, n);
	print(a, n);
}