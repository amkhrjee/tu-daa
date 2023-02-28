#include <iostream>
using namespace std;

int findBuilding(int **, int, int, int);

int main()
{
    int len = 6;
    int **arr = new int *[len];

    // first param = width
    // second param = length
    arr[0] = new int[2]{2, 1};
    arr[1] = new int[2]{3, 3};
    arr[2] = new int[2]{2, 4};
    arr[3] = new int[2]{2, 7};
    arr[4] = new int[2]{2, 9};
    arr[5] = new int[2]{1, 10};

    int x = 8;
    int y = 5;

    int buildingNum = findBuilding(arr, len, x, y);
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
}
int findBuilding(int **arr, int len, int x, int y)
{
    int xCount = 0;
    int yCount = 0;
    bool hitX = false;
    bool hitY = false;
    int buildingIndex = 0;
    while (buildingIndex < len)
    {
        if (!hitX)
        {
            xCount += arr[buildingIndex][0];
            if (xCount > x)
                hitX = true;
        }

        if (!hitY)
        {
            yCount += arr[buildingIndex][1];
            if (yCount < y)
                hitY = true;
        }
        buildingIndex++;
    }
    if (!hitX)
    {
        cout << "Error: X-coordinate " << x << " out of bound." << endl;
        return -1;
    }
    else if (!hitY)
    {
        cout << "Error: Y-coordinate " << y << " out of bound." << endl;
        return -1;
    }
    else
    {
        return buildingIndex - 2;
    }
}
