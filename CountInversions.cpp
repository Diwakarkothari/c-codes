#include <iostream>
using namespace std;

long long int merge(long long *arr, int s, int e)
{
    long long int inv = 0;
    long long int mid = s + (e - s) / 2;
    long long int len1 = mid - s + 1;
    long long int len2 = e - mid;
    long long int arr1[len1];
    long long int arr2[len2];
    long long int mainindex = s;
    for (long long int i = 0; i < len1; i++)
    {
        arr1[i] = arr[mainindex++];
    }
    mainindex = mid + 1;
    for (long long int i = 0; i < len2; i++)
    {
        arr2[i] = arr[mainindex++];
    }
    mainindex = s;
    long long int index1 = 0, index2 = 0;
    while (index1 < len1 && index2 < len2)
    {
        if (arr1[index1] <= arr2[index2])
            arr[mainindex++] = arr1[index1++];
        else
        {
            arr[mainindex++] = arr2[index2++];
            inv += len1 - index1;
        }
    }
    while (index1 < len1)
    {
        arr[mainindex++] = arr1[index1++];
    }
    while (index2 < len2)
    {
        arr[mainindex++] = arr2[index2++];
    }
    return inv;
}

long long int mergesort(long long *arr, int s, int e)
{
    long long int inv = 0;
    if (s < e)
    {
        long long int mid = s + (e - s) / 2;
        inv += mergesort(arr, s, mid);
        inv += mergesort(arr, mid + 1, e);
        inv += merge(arr, s, e);
    }
    return inv;
}

long long int inversionCount(long long arr[], int n)
{
    return mergesort(arr, 0, n - 1);
}