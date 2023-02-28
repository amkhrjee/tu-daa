/*
    Author: Aniruddha Mukehrjee
    Roll No.: CSB21076

    Description: Deals with the first problem recursively.

    The function findMinIndex uses binary search in the heights of the buildings to get teh index where the height first occurs.

    The function findActualIndex checks from the minIndex to the end of the buildings to get to the actual index using the x index

    This approach assumes the widths of the building show no trend.

    This has a worst case performance of O(n).
*/
#include <iostream>
#include <time.h>

using namespace std;

int findMinIndex(int **arr, int left, int right, int x, int y)
{
    int midIndex = (left + right) / 2;
    if (left < right)
    {
        if (y > arr[midIndex][1])
        {
            findMinIndex(arr, midIndex + 1, right, x, y);
        }
        else if (y <= arr[midIndex][1])
        {
            if (midIndex > 0)
            {
                if (y <= arr[midIndex - 1][1])
                {
                    findMinIndex(arr, left, midIndex, x, y);
                }
                else
                    return midIndex;
            }
            else if (arr[midIndex][1] == y)
                return 0;
            else
                return -1;
        }
    }
    else
        return midIndex;
}

int findActualIndex(int *cumDistances, int len, int x, int minIndex)
{
    for (int i = minIndex; i < len; i++)
    {
        if (x < cumDistances[i])
        {
            if (i == 0)
                return 0;
            else
                return i - 1;
        }
    }
}

int main()
{
    int len = 6;
    int **arr = new int *[len];

    // first param = width
    // second param = height
    arr[0] = new int[2]{2, 1};
    arr[1] = new int[2]{3, 3};
    arr[2] = new int[2]{2, 4};
    arr[3] = new int[2]{2, 7};
    arr[4] = new int[2]{2, 9};
    arr[5] = new int[2]{1, 10};

    int *cumulativeDistances = new int[len];
    int xMax = 0;
    for (int i = 0; i < len; i++)
    {
        xMax += arr[i][0];
        cumulativeDistances[i] = xMax;
    }

    int yMax = arr[len - 1][1];

    int x = 11;
    int y = 10;

    int minIndex = findMinIndex(arr, 0, len - 1, x, y) + 1;
    int actualIndex = findActualIndex(cumulativeDistances, len, x, minIndex);
    int buildingNum = actualIndex + 1;

    if (buildingNum == -1)
    {
        cout << "Error: Building Not Found" << endl;
    }
    else
    {
        cout << "Building No. = " << buildingNum << endl;
    }

    for (int i = 0; i < len; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
    delete[] cumulativeDistances;
}