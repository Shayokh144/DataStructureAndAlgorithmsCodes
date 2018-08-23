#include<iostream>
using namespace std;


void merge(int *arr, int low,  int mid, int high)
{
	int rc, lc;
	rc = lc = 0;
	int mainIdx = low;
	int leftA[100];
	int rightA[100];
	int lIdx, rIdx;
	lIdx = rIdx = 0;
	for (int i = low; i <= mid; i++)
	{
		leftA[lIdx] = arr[i];
		lIdx++;
	}

	for (int i = mid + 1; i <= high; i++)
	{
		rightA[rIdx] = arr[i];
		rIdx++;
	}

	int i = 0;
	int j = 0;
	while (i < lIdx && j < rIdx)
	{
		if (leftA[i]>rightA[j])
		{
			arr[mainIdx] = rightA[j];
			j++;
			mainIdx++;
		}
		else
		{
			arr[mainIdx] = leftA[i];
			i++;
			mainIdx++;
		}
	}

	while (i < lIdx)
	{
		arr[mainIdx] = leftA[i];
		i++;
		mainIdx++;
	}
	while (j < rIdx)
	{
		arr[mainIdx] = rightA[j];
		j++;
		mainIdx++;
	}
}


void merge_sort(int *arr, int low, int high)
{
	if (low < high)
	{
		int mid = (low + high) / 2;
		merge_sort(arr, low, mid);
		merge_sort(arr, mid + 1, high);
		merge(arr, low, mid, high);
	}
}

int main()
{
	int n;
	int arr[100];
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	merge_sort(arr, 0, n - 1);

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "  ";
	}
	cout << "\n";
	return 0;
}

/*
5
1 34 2 56 12

6
6 3 11 23 45 3

*/
