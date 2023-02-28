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

    // first param = width
    // // second param = height
    // arr[0] = new int[2]{2, 1};
    // arr[1] = new int[2]{3, 3};
    // arr[2] = new int[2]{2, 4};
    // arr[3] = new int[2]{2, 7};
    // arr[4] = new int[2]{2, 9};
    // arr[5] = new int[2]{1, 10};
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
    end = clock();
    cout << "Running time = " << (double)end - start << endl;
}
