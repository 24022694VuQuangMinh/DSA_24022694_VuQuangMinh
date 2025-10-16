#pragma once
#include <iostream>
using namespace std;

int binarySearch(int array[], int x, int low, int high) {

    // Repeat until the pointers low and high meet each other
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (x == array[mid])
            return mid;

        if (x > array[mid])
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1;
}
