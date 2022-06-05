#include<iostream>
#include <ctime>
#include <chrono>
using namespace std;
void merge(int arr[], int l, int r, int m)
{
	int n1 = m - l + 1;
	int n2 = r - m;
	int i, j, k;
	int* L = new int[n1];
	int* R = new int[n2];
	for (int i = 0; i < n1; i++)
	{
		L[i] = arr[l + i];
	}
	for (int j = 0; j < n2; j++)
	{
		R[j] = arr[m + 1 + j];
	}
	k = l, i = 0, j = 0;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		arr[k] = L[i];
		i++, k++;
	}
	while (j < n2)
	{
		arr[k] = R[j];
		j++, k++;
	}
}
void mergeSort(int arr[], int l, int r)
{
	if (l < r)
	{
		int mid = l + (r - l) / 2;
		mergeSort(arr, l, mid);
		mergeSort(arr, mid + 1, r);
		merge(arr, l, r, mid);
	}
};
void print(int arr[], int size)
{
	int s;
	for (int s = 0; s < size; s++)
		cout << arr[s] << "_";
	cout << endl;
};

int partitionMiddle(int arr[], int l, int r, int pivot)
{
	while (l <= r)
	{
		while (arr[l] < pivot)
		{
			l++;
		}
		while (arr[r] > pivot)
		{
			r--;
		}
		if (l <= r)
		{
			swap(arr[l], arr[r]);
			l++; r--;
		}

	}
	return l;
}
void quickSort(int arr[], int l, int r)
{

	if (l < r)
	{
		int pivot = arr[(l + r) / 2];
		int quick = partitionMiddle(arr, l, r, pivot);
		quickSort(arr, l, quick - 1);
		quickSort(arr, quick, r);
	}
}
int main()
{
	const int s = 5000;
	int arr[s], arr2[s];
	int n = sizeof(arr) / sizeof(arr[0]);
	int m = sizeof(arr2) / sizeof(arr2[0]);
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand();
		arr2[i] = arr[i];
	}
	auto start = chrono::steady_clock::now();
	mergeSort(arr, 0, n - 1);
	auto end = chrono::steady_clock::now();
	auto extime = chrono::duration_cast<chrono::milliseconds>(end - start).count();
	cout << "_________________________________________________________________________________________________________\n";
	cout << "excuted time mergeSort= " << extime << " millisecond" << endl;
	cout << "_________________________________________________________________________________________________________\n";
	print(arr, n);
	cout << "_________________________________________________________________________________________________________\n";
	auto start2 = chrono::steady_clock::now();
	quickSort(arr2, 0, m - 1);
	auto end2 = chrono::steady_clock::now();
	auto extime2 = chrono::duration_cast<chrono::milliseconds>(end2 - start2).count();
	cout << "excuted time for quickSort = " << extime2 << " millisecond" << endl;
	cout << "_________________________________________________________________________________________________________\n";
	print(arr2, m);
}