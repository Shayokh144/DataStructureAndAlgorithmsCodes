#include<iostream>

using namespace std;

int min(int x, int y) { return (x<y) ? x : y; }

void  print_array(int *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "  ";
	}
	cout << "\n";
}


void merge_two_array(int *left,int nL,int *right,int nR, int *arr,int k)
{
	int i, j;
	i = j =  0;

	//cout << "nL = " << nL << "nR = " << nR << "\n";
	while (i < nL&&j < nR)
	{
		//cout << "in while" << " ";
		if (left[i] <= right[j])
		{
			arr[k] = left[i];
			k += 1;
			i += 1;
		}
		else
		{
			arr[k] = right[j];
			k += 1;
			j += 1;
		}
	}

	for (; i < nL; i++)
	{
		//cout << "\nif\n"<<" k ="<<k<<"left = "<<left[i];
		arr[k] = left[i];
		k += 1;
	}
	for (; j < nR; j++)
	{
		arr[k] = right[j];
		k += 1;
	}
	
}


void merge_sort(int *arr,int n)
{
	int mid ;
	int left[100];
	int right[100];
	int stack[100];
	
	int stepSize,leftStart,rightEnd;

	for (stepSize = 1; stepSize <= n - 1; stepSize *= 2)
	{

		for (leftStart = 0; leftStart < n; leftStart += stepSize * 2)
		{
			mid = leftStart+stepSize;
			rightEnd = min(leftStart -1+ (2 * stepSize), n - 1);
			/*
			if n is not in the series of 2^n, overflow can happen, so we have to be inside array length
			*/
			int idx = leftStart;
			int leftCount = 0;
			int rightCount = 0;
			for (; idx < mid; idx++)
			{
				left[leftCount] = arr[idx];
				leftCount += 1;
				//cout << "l= " << left[idx] << "\n";
			}
				

			
			idx = mid;
			for (; idx <= rightEnd; idx++)
			{

				right[rightCount] = arr[idx];
				rightCount += 1;
				//cout << "r= " << right[i] << "\n";
				
			}
			merge_two_array(left, leftCount, right, rightCount, arr,leftStart);
			print_array(arr, n);
		}
	}


	
}



int main()
{
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	int n = sizeof(arr) / sizeof(*arr);
	merge_sort(arr, n);
	print_array(arr, n);
	return 0;
}