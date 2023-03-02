/*
    Author: Aniruddha Mukehrjee
    Roll No.: CSB21076

    Description: Solution to Problem 2.
*/

#include <iostream>
using namespace std;

struct Coordinate
{
    Coordinate(int x = 0, int y = 0) : x(x), y(y){};
    int x;
    int y;
};

struct Rectangle
{
    Rectangle(int width, int height, int x, int y) : width(width), height(height)
    {
        lowerLeftCoordinate.x = x;
        lowerLeftCoordinate.y = y;
    };
    int width;
    int height;
    Coordinate lowerLeftCoordinate;
};

enum RectanglePosition
{
    OUTSIDE,
    PARTIALLY_INSIDE,
    INSIDE
};

RectanglePosition getRectanglePosition(int **, int, Rectangle *);

int main()
{
    // buildings
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

    RectanglePosition recPos = getRectanglePosition(arr, len, new Rectangle(2, 1, 9, 5));

    switch (recPos)
    {
    case INSIDE:
        cout << "Rectangle is completely inside the buildings" << endl;
        break;
    case PARTIALLY_INSIDE:
        cout << "Rectangle is partially inside the buildings" << endl;
        break;
    case OUTSIDE:
        cout << "Rectangle is completely outside the buildings" << endl;
        break;
    default:
        cout << "Some error occured" << endl;
        break;
    }

    return 0;
}

RectanglePosition getRectanglePosition(int **arr, int len, Rectangle *rec)
{
    int index = 0;
    int cumulativeDistance = 0;
    bool isLowerLeftXInside = false;
    bool isLowerRightXInside = false;

    while (index < len)
    {
        if (cumulativeDistance > rec->lowerLeftCoordinate.x)
        {
            isLowerLeftXInside = true;
            break;
        }
        cumulativeDistance += arr[index++][0];
    }
    index -= 1; // accounting for the extra increment

    if (isLowerLeftXInside)
    {
        if (arr[index][1] > rec->lowerLeftCoordinate.y + rec->height)
        {
            return INSIDE;
        }
    }

    while (index < len)
    {
        if (cumulativeDistance > rec->lowerLeftCoordinate.x + rec->width)
        {
            isLowerRightXInside = true;
            break;
        }
        cumulativeDistance += arr[index++][0];
    }
    index -= 1;
    if (isLowerRightXInside)
    {
        if (arr[index][1] > rec->lowerLeftCoordinate.y + rec->height)
        {
            return PARTIALLY_INSIDE;
        }
    }

    if (!isLowerLeftXInside && !isLowerRightXInside)
    {
        return OUTSIDE;
    }
}