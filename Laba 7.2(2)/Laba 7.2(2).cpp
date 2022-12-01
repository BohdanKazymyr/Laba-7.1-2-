#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void CreateRow(int** a, const int i, const int rowCount, const int Low,
	const int High, int j);
void CreateRows(int** a, const int colCount, const int Low, const int High, int i);
void PrintRow(int** a, const int rowNo, const int rowCount, int colNo);
void PrintRows(int** a, const int colCount, int rowNo);
int Sum(int** a, const int n, const int k);
int main()
{
	srand((unsigned)time(NULL));
	int Low = -23;
	int High = 26;
	int n;
	int k;
	cout << "n = "; cin >> n;
	cout << "k = "; cin >> k;
	int** a = new int* [n];
	for (int i = 0; i < n; i++)
		a[i] = new int[k];
	CreateRows(a, n, Low, High, 0);
	PrintRows(a, n, 0);
	cout << "Sum = " << Sum(a, n, k) << endl;
	for (int i = 0; i < n; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}
void CreateRow(int** a, const int rowNo, const int rowCount, const int Low,
	const int High, int colNo)
{
	a[rowNo][colNo] = Low + rand() % (High - Low + 1);
	if (colNo < rowCount - 1)
		CreateRow(a, rowNo, rowCount, Low, High, colNo + 1);
}
void CreateRows(int** a, const int colCount, const int Low, const int High, int rowNo)
{
	CreateRow(a, rowNo, colCount, Low, High, 0);
	if (rowNo < colCount - 1)
		CreateRows(a, colCount, Low, High, rowNo + 1);
}
void PrintRow(int** a, const int rowNo, const int rowCount, int colNo)
{
	cout << setw(4) << a[rowNo][colNo];
	if (colNo < rowCount - 1)
		PrintRow(a, rowNo, rowCount, colNo + 1);
	else
		cout << endl;
}
void PrintRows(int** a, const int colCount, int rowNo)
{
	PrintRow(a, rowNo, colCount, 0);
	if (rowNo < colCount - 1)
		PrintRows(a, colCount, rowNo + 1);
	else
		cout << endl;
}
int Sum(int** a, const int n, const int k)
{
	int max = -23;
	int sum = 0;
	for (int j = 0; j < k; j += 2)
	{
		for (int i = 0; i < n; i++)
		{

			if (a[i][j] >= max)
				max = a[i][j];

		}
		sum += max;
	}
	return sum;
}