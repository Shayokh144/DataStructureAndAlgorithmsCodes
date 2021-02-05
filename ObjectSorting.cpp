
#include <iostream>
using namespace std;

typedef struct DataStruct{
	int data;
	int index;
}Data;

void merge(Data *darr, int low, int mid, int high)
{
	int rc, lc;
	rc = lc = 0;
	int mainIdx = low;
	Data leftA[1000];
	Data rightA[1000];
	int lIdx, rIdx;
	lIdx = rIdx = 0;

	for (int i = low; i <= mid; i++)
	{
		leftA[lIdx] = darr[i];
		lIdx++;
	}

	for (int i = mid + 1; i <= high; i++)
	{
		rightA[rIdx] = darr[i];
		rIdx++;
	}

	int i = 0;
	int j = 0;

	while (i < lIdx && j < rIdx)
	{
		if (leftA[i].data > rightA[j].data)
		{
			darr[mainIdx] = rightA[j];
			j++;
			mainIdx++;
		}
		else if (leftA[i].data == rightA[j].data) {
			if (leftA[i].index > rightA[j].index) {
				darr[mainIdx] = rightA[j];
				j++;
				mainIdx++;
			}
			else {
				darr[mainIdx] = leftA[i];
				i++;
				mainIdx++;
			}
		}
		else
		{
			darr[mainIdx] = leftA[i];
			i++;
			mainIdx++;
		}
	}

	while (i < lIdx)
	{
		darr[mainIdx] = leftA[i];
		i++;
		mainIdx++;
	}

	while (j < rIdx)
	{
		darr[mainIdx] = rightA[j];
		j++;
		mainIdx++;
	}
}

void merge_sort(Data *darr, int low, int high)
{
	if (low < high)
	{
		int mid = (low + high) / 2;
		merge_sort(darr, low, mid);
		merge_sort(darr, mid + 1, high);
		merge(darr, low, mid, high);
	}
}


int main()
{
	int n;
	int input[2000];
	Data dataObjects[2000];

	cout << "Enter number of item: ";
	cin >> n;
	cout << "Enter numbers : ";

	for (int i = 0; i < n; i++) {
		cin >> input[i];
		dataObjects[i].data = input[i];
		dataObjects[i].index = i;
	}

	merge_sort(dataObjects, 0, n - 1);

	for (int i = 0; i < n; i++)
	{
		cout << "value: " << dataObjects[i].data << "       index: "<< dataObjects[i].index <<"\n";
	}
	cout << "\n";
	return 0;
}

/*
input:

Test 1:
7
23 12 13 34 5 222 78

Test 2:
5
2 10 4 3 10

*/
