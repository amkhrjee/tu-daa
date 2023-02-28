#include <iostream>
using namespace std;

int fibSequence(int index)
{
    int count = 1;
    if (index == 0)
    {
        return 0;
    }
    else if (index == 1)
    {
        return 1;
    }
    else
    {
        int prev = 1;
        int prevPrev = 0;
        while (count < index)
        {
            int temp = prev;
            prev += prevPrev;
            prevPrev = temp;
            count++;
        }
        return prev;
    }
}

int maxFibIndex(int len)
{
    int index = 1;
    int prev = 1;
    int prevPrev = 0;
    while (prev < len)
    {
        int temp = prev;
        prev += prevPrev;
        prevPrev = temp;
        index++;
    }
    return index;
}

void fibSearch(int x, int *arr, int maxIndex)
{
    int index = fibSequence(maxIndex - 1);
    if (maxIndex <= 0)
    {
        cout << "Item not present in array" << endl;
    }
    else if (x == arr[maxIndex - 1])
    {
        cout << "Item PRESENT in array" << endl;
    }
    else if (x < arr[index])
    {
        // todo
        fibSearch(x, arr, maxIndex - 1);
    }
    else
    {
        arr = arr + index;
        maxIndex = maxIndex - 2;
        fibSearch(x, arr, maxIndex);
    }
}

int main()
{
    // sorted array
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int len = 10;
    int x;
    cout << "Enter number to be searched: ";
    cin >> x;
    int maxIndex = maxFibIndex(len);
    fibSearch(x, arr, maxIndex);
    return 0;
}
