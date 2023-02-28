#include <iostream>
#define MAXLEN 100
using namespace std;

void printArr(int *arr, int len)
{
	cout << "============================" << endl;
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
int main()
{
	// user input
	int x;
	cout << "Enter the item to be searched: ";
	cin >> x;

	//	dummy array
	int arr[] = {10, 20, 30, 40, 50, -2, -30, 100, 90, 0};
	cout << "The original array: ";
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	int len = 10;

	// max fibonacci index
	int index = 1; //<-- this is the index k
	int prev = 1;
	int prevPrev = 0;
	int fibArr[MAXLEN] = {prevPrev, prev};
	while (prev < len)
	{
		int temp = prev;
		prev += prevPrev;
		prevPrev = temp;
		fibArr[++index] = prev;
	}

	// print the Fibonacci array
	cout << "Fibonacci array: ";
	for (int i = 0; i <= index; i++)
	{
		cout << fibArr[i] << " ";
	}
	cout << endl;
	int iter = 0;
	cout << "Value of index = " << index << endl;
	while (index)
	{
		cout << "Entered loop iteration = " << iter++ << endl;
		cout << "Array index = " << fibArr[index - 1] << endl;
		int arrIndex = fibArr[index - 1];
		cout << "Item at that index = " << arr[arrIndex] << endl;
		if (x == arr[arrIndex])
		{
			cout << "Item PRESENT in array" << endl;
			return 0;
		}
		else if (x < arr[arrIndex])
		{
			cout << "Array item more than x" << endl;
			int rightIndex = fibArr[index - 1] + 1;
			int newIndex = 0;
			for (int i = 0; i < len; i++)
			{
				if (i < rightIndex)
				{
					arr[newIndex++] = arr[i];
					cout << "Added at index" << i << " = " << arr[i] << endl;
				}
			}
			cout << "Array len before = " << len << endl;
			len = rightIndex;
			index = index - 1;
			cout << "Array len after = " << len << endl;
			printArr(arr, len);
		}
		else
		{
			cout << "Array item less than x" << endl;
			int leftIndex = fibArr[index - 1];
			int newIndex = 0;
			for (int i = 0; i < len; i++)
			{
				if (i > leftIndex)
				{
					cout << "Item added at index " << newIndex;
					arr[newIndex++] = arr[i];
					cout << " = " << arr[i] << endl;
				}
			}
			cout << "array len before = " << len << endl;
			len = len - leftIndex - 1;
			cout << "array len after = " << len << endl;
			index = index - 2;
			// printArr(arr, len);
		}
		cout << "-----------------------------" << endl;
	}
	cout << "Item NOT PRESENT in array" << endl;
	return 0;
}
