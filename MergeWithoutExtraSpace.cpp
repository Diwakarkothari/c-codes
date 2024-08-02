#include <iostream>
#include<algorithm>
using namespace std;
void merge(long long arr1[], long long arr2[], int n, int m)
{
    // code here

    int i = n - 1, j = 0;
    while (i >= 0 && j < m)
    {
        if (arr1[i] > arr2[j])
        {
            swap(arr1[i], arr2[j]);
            i--;
            j++;
        }
        else
            break;
    }
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);

    // TLE
    // for(int j=0;j<m;j++)
    // {
    //     int i=0;
    //     while(i<n)
    //     {
    //         if(arr1[i]>arr2[j])
    //         {
    //             swap(arr1[i],arr2[j]);
    //         }
    //         i++;
    //     }
    // }
    // sort(arr2,arr2+m);1
}