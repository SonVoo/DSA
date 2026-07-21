#include <iostream>
#include <ctime>
#include <cstdlib> // Thư viện chứa hàm rand() và srand()
using namespace std;

// Khai báo mảng toàn cục kích thước 1 triệu phần tử để tránh tràn bộ nhớ Stack
double a[(int)1e6];

// Hàm khởi tạo 100.000 phần tử ngẫu nhiên theo hình của bạn
void initDataArr100k(double a[], int& n)
{
	n = 100000;
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() + (rand() % 1001) / 1000.0;
	}
}

void print(double a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

void selectionSort(double a[], int n)
{
	int min;
	for (int i = 0; i < n - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[min])
				min = j;
		}
		if (min != i)
			swap(a[min], a[i]);
	}
}

void insertionSort(double a[], int n)
{
	for (int i = 1; i < n; i++)
	{
		double temp = a[i];
		int j;
		for (j = i - 1; j >= 0; j--)
		{
			if (a[j] < temp)
				break;
			a[j + 1] = a[j];
		}
		a[j + 1] = temp;
	}
}

double timeSort(double a[], int n, int loai)
{
	if (loai == 1)
	{
		double s = clock();
		selectionSort(a, n);
		double e = clock();
		return (double)(e - s) / CLOCKS_PER_SEC;
	}
	else if (loai == 2)
	{
		double s = clock();
		insertionSort(a, n);
		double e = clock();
		return (double)(e - s) / CLOCKS_PER_SEC;
	}
	return 0;
}

int main()
{
	srand(time(0)); // Khởi tạo seed để mỗi lần chạy ngẫu nhiên ra số khác nhau
	int n = 0;

	// Khởi tạo mảng 100.000 phần tử ngẫu nhiên
	initDataArr100k(a, n);

	cout << "da khoi tao xong " << n << " phan tu ngau nhien." << endl;
	cout << "dang chay thuat toan sap xep, vui long cho..." << endl;

	// Đo thời gian chạy của Insertion Sort (loại 2)
	double t = timeSort(a, n, 2);

	cout << "thoi gian chay: " << t << " s" << endl;

	return 0;
}