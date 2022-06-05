#include<iostream>
#include <ctime>
#include <chrono>
using namespace std;
void insertionSort(int arr[], int size)
{
	int temp;
	for (int i = 1; i < size; i++)
	{
		temp = arr[i];
		int j = i;
		while (j >= 1 && arr[j - 1] > temp)
		{
			arr[j] = arr[j - 1];
			j--;
		}
		arr[j] = temp;
	}

}

int binarySearch(int arr[], int l, int r, int key)
{

	if (r <= l)
	{
		if (key > arr[l])
		{
			return (l + 1);
		}
		else
		{
			return l;
		}
	}
	int mid = l + (r - l) / 2;

	if (arr[mid] == key)
	{
		return (mid + 1);
	}

	if (key > arr[mid])
	{
		return binarySearch(arr, mid + 1, r, key);
	}
	return binarySearch(arr, l, mid - 1, key);
}
void bianryInsertionSort(int a[], int size)
{
	int i, loc, j, k, selected;

	for (i = 1; i < size; ++i)
	{
		j = i;
		selected = a[i];
		loc = binarySearch(a, 0, j - 1, selected);
		while (j - 1 >= loc)
		{
			a[j] = a[j - 1];
			j--;
		}
		a[j] = selected;
	}
}


void print(int arr[], int size)
{
	int s;
	for (int s = 0; s < size; s++)
		cout << arr[s] << "_";
	cout << endl;
};
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
	insertionSort(arr, n);
	auto end = chrono::steady_clock::now();
	auto extime = chrono::duration_cast<chrono::milliseconds>(end - start).count();
	cout << "_________________________________________________________________________________________________________\n";
	cout << "excuted time insertionSort = " << extime << " millisecond" << endl;
	cout << "_________________________________________________________________________________________________________\n";
	print(arr, n);
	cout << "_________________________________________________________________________________________________________\n";
	auto start2 = chrono::steady_clock::now();
	bianryInsertionSort(arr2, m);
	auto end2 = chrono::steady_clock::now();
	auto extime2 = chrono::duration_cast<chrono::milliseconds>(end2 - start2).count();
	cout << "excuted time for bianryInsertionSort = " << extime2 << " millisecond" << endl;
	cout << "_________________________________________________________________________________________________________\n";
	print(arr2, m);

}