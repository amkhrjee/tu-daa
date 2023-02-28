Design and Analysis of Algorithms (CO206)
B.Tech. 4th Semester Spring Semester 2023
Assignment details
Assignment 3
ARINDAM KARMAKAR
•
Feb 16 (Edited Feb 16)
100 points
Due Feb 22, 11:59 PM

assign-3.pdf
PDF
Class comments
Your work
Turned in

one_recursive.cpp
Text

one_iterative.cpp
Text

two_iterative.cpp
Text

two_recursive.cpp
Text

Scanned_20230222-2342.pdf
PDF
Private comments
/*
    RECURSIVE SOLUTION TO PROBLEM 1
    Author: Aniruddha Mukherjee
    Roll No. : CSB21076
*/

#include <iostream>
#include <fstream>
using namespace std;

void writeToFile(int);
void readFromFile(int *);
void printArr(int *, int);
void sort(int *, int, int);
void merge(int *, int, int, int);
bool fibSearch(int *, int, int, int, int, int);

int main()
{
    // user input
    bool correctInput = false;
    int len;
    while (!correctInput)
    {
        cout << "Enter the length for random array: ";
        cin >> len;
        if (len > 0)
        {
            // writeToFile(len);
            correctInput = true;
        }
        else
        {
            cout << "Input must be greater than 0 (zero)" << endl;
        }
    }

    int x;
    cout << "Enter the number to be searched for: ";
    cin >> x;

    writeToFile(len);

    // reading from the file
    int *arr = new int[len];
    readFromFile(arr);
    sort(arr, 0, len - 1);

    int index = 2;
    int prev = 1;
    int prevPrev = 0;
    while (prev < len)
    {
        int temp = prev;
        prev += prevPrev;
        prevPrev = temp;
        index++;
    }
    bool isPresent = fibSearch(arr, len, x, index, prev, prevPrev);
    delete[] arr;
    if (isPresent)
    {
        cout << "Item PRESENT in array" << endl;
    }
    else
    {
        cout << "Item NOT PRESENT in array" << endl;
    }
}

bool fibSearch(int *arr, int len, int x, int index, int prev, int prevPrev)
{
    int arrIndex = prevPrev;
    int arrVal = arr[arrIndex];

    if (index > 0)
    {
        printArr(arr, len);
        if (x == arrVal)
        {
            return true;
        }
        else if (x < arrVal)
        {
            int temp = prevPrev;
            prevPrev = prev - prevPrev;
            prev = temp;
            fibSearch(arr, arrIndex + 1, x, index - 1, prev, prevPrev);
        }
        else
        {
            prev = prev - prevPrev;
            prevPrev = prevPrev - prev;

            fibSearch(arr + arrIndex + 1, len - arrIndex - 1, x, index - 2, prev, prevPrev);
        }
    }
    else
    {
        return false;
    }
}
// a simple function that prints array
void printArr(int *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
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

void merge(int *arr, int left, int mid, int right)
{
    int index = 0;
    int *tempArr = new int[right - left + 1];

    // iterators
    int i = left;
    int j = mid + 1;
    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            tempArr[index++] = arr[i++];
        }
        else
        {
            tempArr[index++] = arr[j++];
        }
    }

    // adding the leftovers
    while (i <= mid)
    {
        tempArr[index++] = arr[i++];
    }

    while (j <= right)
    {
        tempArr[index++] = arr[j++];
    }

    // writing to the original array
    for (int i = 0; i < index; i++)
    {
        arr[left + i] = tempArr[i];
    }

    delete[] tempArr;
}

void sort(int *arr, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        sort(arr, left, mid);
        sort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}
