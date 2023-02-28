#include <iostream>
using namespace std;

void swap(int *, int, int);
void partition(int *, int, int, int);
void printArr(int *, int);

int main()
{
    int pivot = 20;
    int arr[] = {1, 2, 3, -1, 33, 20, 100, -9, 0, 34, 500, -34, 20, 33};
    int len = 14;
    cout << "Before partition:" << endl;
    printArr(arr, len);
    // perform partition
    partition(arr, 0, len - 1, pivot);

    cout << "After partition:" << endl;
    printArr(arr, len);
}

void printArr(int *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void swap(int *arr, int first, int second)
{
    // !!!caution: doesn't check whether the indices are valid or not
    int temp = arr[first];
    arr[first] = arr[second];
    arr[second] = temp;
    cout << "Swapped " << arr[first] << " with " << arr[second] << endl;
}

void partition(int *arr, int left, int right, int pivot)
{
    int uc = left;
    int lb, eb;
    int rightIndex = right;
    lb = left - 1;
    eb = lb;
    bool firstEqual = false;
    int distanceFromLB;

    cout << "Entering rearrangements: " << endl;
    while (uc <= right)
    {
        firstEqual ? distanceFromLB += 1 : distanceFromLB = 0;
        if (arr[uc] > pivot)
        {
            if (!firstEqual)
            {
                swap(arr, uc, rightIndex--);
            }
            else
                uc++;
        }
        else if (arr[uc] < pivot)
        {
            if (!firstEqual)
            {
                lb++;
                uc++;
            }
            else
            {
                int index = distanceFromLB;
                int tempUC = uc;
                while (index > 0)
                {
                    swap(arr, tempUC, tempUC - 1);
                    tempUC -= 1;
                    index--;
                }
                uc++;
                eb++;
                distanceFromLB -= 1;
            }
        }
        else
        {
            if (!firstEqual)
            {
                firstEqual = true;
                eb = lb + 1;
                uc++;
            }
            else
            {
                int index = distanceFromLB;
                int tempUC = uc;
                while (index > 1)
                {
                    swap(arr, tempUC, tempUC - 1);
                    tempUC -= 1;
                    index--;
                }
                uc++;
                eb++;
            }
        }
        printArr(arr, right - left + 1);
        cout << "----------------------------" << endl;
    }
}