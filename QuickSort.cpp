#include <iostream>
using namespace std;
int pivot(long long *arr, int s, int e)
{
    int pivot = s;
    int count = 0;
    for (int i = s; i <= e; i++)
    {
        if (arr[i] < arr[pivot])
            count++;
    }
    pivot += count;
    swap(arr[s], arr[pivot]);
    int i = s, j = e;
    while (i < pivot && j > pivot)
    {
        while (arr[i] < arr[pivot])
            i++;
        while (arr[j] > arr[pivot])
            j--;
        if (i < pivot and j > pivot)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    return pivot;
}

void quicksort(long long *arr, int s, int e)
{
    if (s >= e)
        return;
    int p = pivot(arr, s, e);
    quicksort(arr, s, p - 1);
    quicksort(arr, p + 1, e);
}

int main()
{
    long long arr[5]={2,3,4,5,6};
    quicksort(arr,0,4);
    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}