#include <iostream>
#include <fstream>
using namespace std;
void writeToFile(int len)
{
	ofstream arrFile("ArrFile.txt");
	int randomArr[len];
	for (int i : randomArr)
	{
		i = rand() % 100;
		arrFile << i << " ";
	}
	arrFile.close();
}
void printArray(int *arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
int compareInGroupofTwo(int *arr, int len)
{
	int max;
	if (len == 1)
	{
		max = *arr;
		return max;
	}
	else if (len % 2 == 0)
	{
		int j = 0;
		for (int i = 0; i < len - 1; i += 2)
		{
			arr[i] > arr[i + 1] ? max = arr[i] : max = arr[i + 1];
			arr[j++] = max;
		}
		printArray(arr, len / 2);
		compareInGroupofTwo(arr, len / 2);
	}
	else
	{
		int last = arr[len - 1];
		int j = 0;
		for (int i = 0; i < len - 1; i += 2)
		{
			arr[i] > arr[i + 1] ? max = arr[i] : max = arr[i + 1];
			arr[j++] = max;
		}
		arr[j] = last;
		printArray(arr, len / 2 + 1);
		compareInGroupofTwo(arr, len / 2 + 1);
	}
}

int main()
{
	int len;
	cout << "Enter the length of the array: ";
	cin >> len;
	writeToFile(len);

	// reading from the file
	ifstream arrFile("ArrFile.txt");
	int arr[len];
	int num, i = 0;
	arrFile >> num;
	while (!arrFile.eof())
	{
		arr[i++] = num;
		arrFile >> num;
	}
	arrFile.close();

	// print the original array
	for (int i : arr)
	{
		cout << i << " ";
	}
	cout << endl;
	cout << "max: " << compareInGroupofTwo(arr, len) << endl;
	return 0;
}
