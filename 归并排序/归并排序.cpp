#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void ArrayOut(int a[], int start, int end, int n);
void Merge(int a[], int left, int mid, int right,int n,int &count_inversion);
void MergeSort(int a[], int left, int right, int n, int &count_inversion);

void ArrayOut(int a[], int start, int end, int n)
{
	if (start < 0 || end >= n)
	{
		cout << "Array Overflow!" << endl;
		exit(-1);
	}
	for (int i = start;i <= end;i++)
		cout << a[i] << " ";
	cout << endl;
}


void Merge(int a[], int left, int mid, int right, int n, int &count_inversion)
{
	if (left == right)
		return;
	
	int len1 = mid - left + 1;
	int len2 = right - (mid + 1) + 1;

	int *p = new int[len1];
	int *q = new int[len2];

	for (int i = 0;i < len1;i++)
	{
		p[i] = a[left + i];
	}

	for (int i = 0;i < len2;i++)
	{
		q[i] = a[mid + 1 + i];
	}

	//ArrayOut(p, 0, len1 -1, n);
	//ArrayOut(q, 0, len2 -1, n);
	int index_1 = 0;
	int index_2 = 0;

	for (int i = left;i <= right;i++)
	{
		if (index_1 < len1 && index_2 < len2)
		{
			if (p[index_1] <= q[index_2])
			{
				a[i] = p[index_1];
				index_1++;
			}
			else
			{
				a[i] = q[index_2];
				index_2++;
				count_inversion +=len1 - index_1;
			}
		}
		else if (index_1 < len1)
		{
			a[i] = p[index_1];
			index_1++;
		}
		else if (index_2 < len2)
		{
			a[i] = q[index_2];
			index_2++;
		}
		else
			return;
	}
	

}
void MergeSort(int a[], int left, int right,int n, int &count_inversion)
{
	if (left >= right)
		return;

	int mid = (left + right) / 2;
	MergeSort(a, left, mid, n, count_inversion);
	MergeSort(a, mid + 1, right, n, count_inversion);
	Merge(a, left, mid, right, n, count_inversion);
}

int main()
{
	int n = 0;
	while (cin >> n)
	{
		int *a = new int[n];
		int *b = new int[n];//for test

		for (int i = 0;i < n;i++)
			cin >> a[i];

		for (int i = 0;i < n;i++)//copy
			b[i] = a[i];


		int count_inversion = 0;
		MergeSort(a, 0, n - 1, n, count_inversion);
		ArrayOut(a, 0, n - 1, n);
		sort(b, b + n);//use the algorithm
		ArrayOut(b, 0, n - 1, n);


		cout << count_inversion << endl;
		//Merge(a, 0, (n - 1) / 2, n - 1, n);


	}
}