#include <iostream>
#include <time.h>
using namespace std;

int findBuilding(int **, int, int, int);

int main()
{
    clock_t start, end;
    start = clock();
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

    int x = 6;
    int y = 3;

    int buildingNum = findBuilding(arr, len, x, y) + 1;
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
    end = clock();
    cout << "Running time = " << (double)end - start << endl;
}

int findBuilding(int **arr, int len, int x, int y)
{
    int xCount = 0;
    int yCount = 0;
    bool hitX = false;
    bool hitY = false;
    int buildingIndex = 0;

    // checks the x coordinate
    while (buildingIndex < len && !hitX)
    {
        xCount += arr[buildingIndex++][0];
        if (xCount > x)
            hitX = true;
    }

    // checks the y coordinate
    if (y <= arr[buildingIndex - 1][1])
    {
        hitY = true;
    }

    if (!hitX)
    {
        cout << "Error: X-coordinate " << x << " out of bound." << endl;
    }
    else if (!hitY)
    {
        cout << "Error: Y-coordinate " << y << " out of bound." << endl;
    }

    return buildingIndex - 1;
    ;
}
