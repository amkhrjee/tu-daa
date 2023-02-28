/*
	ITERATIVE SOLUTION TO PROBLEM 1
	Author: Aniruddha Mukherjee
	Roll No. : CSB21076
*/

#include <iostream>
#include <fstream>
using namespace std;

// function declarations
void writeToFile(int);
void readFromFile(int *);
void printArr(int *, int);
void sort(int *, int, int);
void merge(int *, int, int, int);

int main()
{
	// user input
	bool correctInput = false;
	int len;
	while (!correctInput)
	{
		cout << "Enter the length for random array: ";
		cin >> len;
		if (len > 0)
		{
			// writeToFile(len);
			correctInput = true;
		}
		else
		{
			cout << "Input must be greater than 0 (zero)" << endl;
		}
	}

	int x;
	cout << "Enter the number to be searched for: ";
	cin >> x;

	writeToFile(len);

	// reading from the file
	int *arr = new int[len];
	readFromFile(arr);
	sort(arr, 0, len - 1);

	int index = 2; // <-- this is the index k
	int prevPrev = 0;
	int prev = 1;
	while (prev < len)
	{
		int temp = prev;
		prev += prevPrev;
		prevPrev = temp;
		index++;
	}

	while (index > 0)
	{
		int arrIndex = prevPrev;	// F(k-1)
		int arrVal = arr[arrIndex]; // A[F(k-1)]

		if (x == arrVal)
		{
			cout << "Item PRESENT in array" << endl;
			delete[] arr;
			return 0;
		}
		else if (x < arrVal)
		{
			index = index - 1;

			// sets the correct fibonacci numbers
			int temp = prevPrev;
			prevPrev = prev - prevPrev;
			prev = temp;

			// sets the correct length
			len = arrIndex + 1;
			printArr(arr, len);
		}
		else
		{
			index = index - 2;
			// sets the correct Fibonacci numbers
			prev = prev - prevPrev;
			prevPrev = prevPrev - prev;

			// shifting the array to the right
			arr = arr + arrIndex + 1;
			len = len - arrIndex - 1;
			printArr(arr, len);
		}
	}

	cout << "Item NOT PRESENT in array" << endl;
	delete[] arr;
	return 0;
}

// write to a file in the same directory
void writeToFile(int len)
{
	ofstream arrFile("Array.txt");
	for (int i = 0; i < len; i++)
	{
		arrFile << rand() % 100 << " ";
	}
	arrFile.close();
}

void readFromFile(int *arr)
{
	ifstream arrFile("Array.txt");
	int num, i = 0;
	arrFile >> num;
	while (!arrFile.eof())
	{
		arr[i++] = num;
		arrFile >> num;
	}
}

void merge(int *arr, int left, int mid, int right)
{
	int index = 0;
	int *tempArr = new int[right - left + 1];

	// iterators
	int i = left;
	int j = mid + 1;
	while (i <= mid && j <= right)
	{
		if (arr[i] <= arr[j])
		{
			tempArr[index++] = arr[i++];
		}
		else
		{
			tempArr[index++] = arr[j++];
		}
	}

	// adding the leftovers
	while (i <= mid)
	{
		tempArr[index++] = arr[i++];
	}

	while (j <= right)
	{
		tempArr[index++] = arr[j++];
	}

	// writing to the original array
	for (int i = 0; i < index; i++)
	{
		arr[left + i] = tempArr[i];
	}

	delete[] tempArr;
}

void sort(int *arr, int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		sort(arr, left, mid);
		sort(arr, mid + 1, right);

		merge(arr, left, mid, right);
	}
}

// a simple function that prints array
void printArr(int *arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

