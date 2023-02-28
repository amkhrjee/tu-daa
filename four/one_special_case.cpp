/*
    Author: Aniruddha Mukehrjee
    Roll No.: CSB21076

    Description: This deals with a special case of the problem one when the widths of the buildings are monotonically increasing.

    This has a worst case performance of O(lgn).
*/

#include <iostream>
using namespace std;

int findBuilding(int *cumDist, int left, int right, int x)
{
    int midIndex = (left + right) / 2;

    if (x > cumDist[midIndex])
        findBuilding(cumDist, midIndex + 1, right, x);
    else if (x < cumDist[midIndex])
    {
        if (x > cumDist[midIndex - 1] || midIndex == 0)
            return midIndex;
        findBuilding(cumDist, left, midIndex, x);
    }
}

bool isYinBound(int **arr, int index, int y)
{
    if (arr[index][1] >= y)
        return true;
    else
        return false;
}

int main()
{
    int len = 6;
    int **arr = new int *[len];

    // first param = width
    // second param = height
    arr[0] = new int[2]{2, 1};
    arr[1] = new int[2]{4, 3};
    arr[2] = new int[2]{6, 4};
    arr[3] = new int[2]{8, 7};
    arr[4] = new int[2]{23, 9};
    arr[5] = new int[2]{129, 10};

    int *cumulativeDistances = new int[len];
    int temp = 0;
    for (int i = 0; i < len; i++)
    {
        temp += arr[i][0];
        cumulativeDistances[i] = temp;
    }

    int x = 7;
    int y = 3;
    int index = findBuilding(cumulativeDistances, 0, len - 1, x);

    if (isYinBound(arr, index, y))
    {
        cout << "Building No. = " << index + 1 << endl;
    }
    else
    {
        cout << "No building exists at given coordinate" << endl;
    }

    for (int i = 0; i < len; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
    delete[] cumulativeDistances;

    return 0;
}