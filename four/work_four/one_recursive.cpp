#include <iostream>
using namespace std;

int findBuilding(int **arr, int left, int right, int x, int y)
{
    int buildingIndex;
    if (left < right)
    {
        int mid = (left + right) / 2;
        if (y <= arr[mid][1])
        {
            int buildingIndex = left;
            bool hitX = false;
            int xCount = 0;
            while (buildingIndex <= right)
            {
                if (!hitX)
                {
                    xCount += arr[buildingIndex][0];
                    if (xCount > x)
                        hitX = true;
                }
                buildingIndex++;
            }
            return buildingIndex - 2;
        }
        else
        {
            return findBuilding(arr, mid + 1, right, x, y);
        }
    }
}

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
    int y = 1;

    int totalX = 0;
    for (int i = 0; i < len; i++)
    {
        totalX += arr[i][0];
    }

    int buildingNum = findBuilding(arr, 0, len - 1, x, y);
    if (buildingNum == -1)
    {
        cout << "Error: Building Not Found" << endl;
    }
    else
    {
        cout << "Building No. = " << buildingNum << endl;
    }

    //freeing the memory
    for (int i = 0; i < len; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
}
