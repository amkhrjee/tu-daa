#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	int arr[] = {5, 9, 15, 25, 33, 2, 141, 10, 9, 4, 53, 64};
	// find the maximum element
	int max;
	int len = 0;
	// length of the  array
	for (int i : arr)
	{
		cout << i << " ";
		len++;
	}
	cout << endl;
	if (len % 2 == 0)
	{
		while (len != 0)
		{
			int j = 0;
			for (int i = 0; i < len; i += 2)
			{
				arr[i] > arr[i + 1] ? max = arr[i] : max = arr[i + 1];
				arr[j++] = max;
			}
			len = len / 2;
			for (int k = 0; k < len; k++)
			{
				cout << arr[k] << " ";
			}
			cout << endl;
		}
		cout << "max = " << arr[0] << endl;
	}
	// odd case
	else
	{
		while (len != 0)
		{
			int j = 0;
			for (int i = 0; i < len; i += 2)
			{
				arr[i] > arr[i + 1] ? max = arr[i] : max = arr[i + 1];
				arr[j++] = max;
			}
			arr[j] = arr[len];
			len = len / 2;
		}
		cout << "max = " << arr[0] << endl;
	}
	return 0;
}