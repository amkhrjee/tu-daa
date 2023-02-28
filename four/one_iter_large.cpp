#include <iostream>
#include <time.h>
using namespace std;

int findBuilding(int **, int, int, int);

void randomBuildings(int **arr, int len)
{
    int height = 1;
    for (int i = 0; i < len; i++)
    {
        int randomNum = rand() % 1000;
        arr[i] = new int[2]{randomNum, height + randomNum};
    }
}

int main()
{
    clock_t start, end;
    int len = 100000;
    int **arr = new int *[len];

    randomBuildings(arr, len);

    int *cumulativeDistances = new int[len];
    int xMax = 0;
    for (int i = 0; i < len; i++)
    {
        xMax += arr[i][0];
        cumulativeDistances[i] = xMax;
    }

    int yMax = arr[len - 1][1];

    cout << "Maximum possible X coordinate = " << xMax << endl;
    cout << "Maximum possible Y coordinate = " << yMax << endl;
    int x, y;
    cout << "Enter X coordinate: ";
    cin >> x;

    cout << "Enter Y coordinate: ";
    cin >> y;

    start = clock();
    int buildingNum = findBuilding(arr, len, x, y) + 1;
    cout << "Building Details" << endl;
    cout << "Width = " << arr[buildingNum - 1][0]
         << " Height = " << arr[buildingNum - 1][1] << endl;
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
