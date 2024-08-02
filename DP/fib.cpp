#include<iostream>
#include<vector>
using namespace std;

// recursion
int fib(int n)
{
    if(n<=0)
        return 0;

    if(n==1)
        return 1;
    
    return fib(n-1)+fib(n-2);
}

// recursion + memoization
int fibMem(int n,vector<int>& arr)
{
    if(n<=0)
        return 0;

    if(n==1)
        return 1;
    
    if(arr[n]!=-1)
        return arr[n];
    
    arr[n] = fibMem(n-1,arr)+fibMem(n-2,arr);
    return arr[n];
}

int fibTab(int n)
{
    vector<int> arr(n+1);
    arr[0]=0;
    arr[1]=1;
    for(int i=2;i<=n;i++)
    {
        arr[i] = arr[i-1]+arr[i-2];
    }
    return arr[n];
}

int fibOptimized(int n)
{
    int first=0;
    int second=1;
    if(n==0)
        return first;
    if(n==1)
        return second;
    
    int ans;
    for(int i=2;i<=n;i++)
    {
        int ans=first+second;
        first=second;
        second=ans;
    }
    return second;
}


int main()
{
    // cout<<fib(5);
    // vector<int> arr(6,-1);
    // cout<<fibMem(5,arr);
    cout<<fibTab(5);
    return 0;
}