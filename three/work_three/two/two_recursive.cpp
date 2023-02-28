/*
	RECURSIVE SOLUTION TO PROBLEM 2
	Author: Aniruddha Mukherjee
	Roll No. : CSB21076

	Some Note:
	While I tried out several different possibilities to get to a recursive solution, none of them quite worked. The closest I  got to a solution (at least I thought) was when I tried to divide the problem into two functions - one to rearrange and other to recursively do the partitioning, although, I could not get it working.

	This is the closest solution I have got, that works *most* of the time. It has irregularities and sometimes just won't work.

	It would be great if you would provide me with the algorithm (or perhaps a hint) for this problem.
*/

#include <iostream>
#include <fstream>
using namespace std;

void writeToFile(int);
void readFromFile(int *);
void swap(int *, int, int);
void partition(int *, int, int, int);
void printArr(int *, int);
int eb, lb, distanceFromLb;
bool firstEqual = false;
int main()
{
	bool correctInput = false;
	int len;
	while (!correctInput)
	{
		cout << "Enter the length for random array: ";
		cin >> len;
		if (len > 0)
		{
			correctInput = true;
		}
		else
		{
			cout << "Input must be greater than 0 (zero)" << endl;
		}
	}

	writeToFile(len);

	// reading from the file
	int *arr = new int[len];
	readFromFile(arr);

	printArr(arr, len);

	int pivot;
	bool isPivotPresent = false;
	while (!isPivotPresent)
	{
		cout << "Choose a pivot: ";
		cin >> pivot;

		for (int i = 0; i < len; i++)
		{
			if (arr[i] == pivot)
			{
				isPivotPresent = true;
			}
		}
		if (!isPivotPresent)
			cout << "Pivot does not exist in array" << endl;
	}
	cout << "Before Partition:" << endl;
	printArr(arr, len);

	lb = eb = -1;
	partition(arr, 0, len - 1, pivot);

	cout << "After Partition:" << endl;
	printArr(arr, len);
}

void printArr(int *arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void partition(int *arr, int left, int right, int pivot)
{
	if (left <= right)
	{
		firstEqual ? distanceFromLb += 1 : distanceFromLb = 0;
		if (arr[left] > pivot)
		{
			if (!firstEqual)
			{
				swap(arr, left, right--);
				partition(arr, left, right, pivot);
			}
			else
			{
				partition(arr, left++, right, pivot);
			}
		}
		else if (arr[left] < pivot)
		{
			if (!firstEqual)
			{
				lb++;
				partition(arr, left + 1, right, pivot);
			}
			else
			{
				int index = distanceFromLb;
				int tempUC = left;
				while (index > 0)
				{
					swap(arr, tempUC, tempUC - 1);
					tempUC--;
					index--;
				}
				eb++;
				distanceFromLb--;
				partition(arr, left + 1, right, pivot);
			}
		}
		else
		{
			if (!firstEqual)
			{
				firstEqual = true;
				eb = lb + 1;
				partition(arr, left + 1, right, pivot);
			}
			else
			{
				int index = distanceFromLb;
				int tempUC = left;
				while (index > 1)
				{
					swap(arr, tempUC, tempUC - 1);
					tempUC -= 1;
					index--;
				}
				eb++;
				partition(arr, left + 1, right, pivot);
			}
		}
	}
}
void swap(int *arr, int first, int second)
{
	// !!!caution: doesn't check whether the indices are valid or not
	int temp = arr[first];
	arr[first] = arr[second];
	arr[second] = temp;
	cout << "Swapped " << arr[first] << " with " << arr[second] << endl;
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
