#include <iostream>
using namespace std;
void merge(long long *arr, int s, int e)
{
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
}

void mergesort(long long *arr, int s, int e)
{
    if (s >= e)
        return;

    long long int mid = s + (e - s) / 2;
    mergesort(arr, s, mid);
    mergesort(arr, mid + 1, e);
    merge(arr, s, e);
}

int main()
{
    long long arr[5] = {1,4,2,5,3};
    mergesort(arr, 0, 4);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}