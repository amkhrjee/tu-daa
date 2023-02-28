/*
    ITERATIVE SOLUTION TO PROBLEM 2
    Author: Aniruddha Mukherjee
    Roll No. : CSB21076
*/

#include <iostream>
#include <fstream>
using namespace std;

void writeToFile(int);
void readFromFile(int *);
void swap(int *, int, int);
void partition(int *, int, int, int);
void printArr(int *, int);

int main()
{
    bool correctInput = false;
    int len;
    while (!correctInput)
    {
        cout << "Enter the length for random array: ";
        cin >> len;
        if (len > 0)
        {
            correctInput = true;
        }
        else
        {
            cout << "Input must be greater than 0 (zero)" << endl;
        }
    }

    writeToFile(len);

    // reading from the file
    int *arr = new int[len];
    readFromFile(arr);

    printArr(arr, len);

    int pivot;
    bool isPivotPresent = false;
    while (!isPivotPresent)
    {
        cout << "Choose a pivot: ";
        cin >> pivot;

        for (int i = 0; i < len; i++)
        {
            if (arr[i] == pivot)
            {
                isPivotPresent = true;
            }
        }
        if (!isPivotPresent)
            cout << "Pivot does not exist in array" << endl;
    }

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

// write to a file in the same directory
void writeToFile(int len)
{
    ofstream arrFile("Array.txt");
    for (int i = 0; i < len; i++)
    {
        arrFile << rand() % 100 << " ";
    }
    arrFile.close();
}

void readFromFile(int *arr)
{
    ifstream arrFile("Array.txt");
    int num, i = 0;
    arrFile >> num;
    while (!arrFile.eof())
    {
        arr[i++] = num;
        arrFile >> num;
    }
}
