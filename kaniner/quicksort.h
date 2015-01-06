#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <iostream>

using namespace std;

int pivot(Kanin arr[], int left, int right) {
    return left + (right - left)/2;
}

int partition(Kanin arr[], int left, int right)
{
    int index = pivot(arr, left, right);
    int value = arr[index].getAgility();
    swap(arr[index], arr[right]);
    int pos = left;
    for(int i = left; i < right; i++) {
        if(arr[i].getAgility() < value) {
            swap(arr[i], arr[pos]);
            pos++;
        }
    }
    swap(arr[pos], arr[right]);
    return pos;
}

void quicksort(Kanin arr[], int left, int right)
{
    if(left < right) {
        int p = partition(arr, left, right);
        quicksort(arr, left, p - 1);
        quicksort(arr, p + 1, right);
    }
}

#endif
