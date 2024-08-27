#include<iostream>
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

int solve(int arr[],int s,int e)
{
    int mid = (s+e)/2;
    while(s<e)
    {
        if(arr[mid]<arr[s])
            e=mid-1;
        else if(arr[mid]>arr[s])
            s=mid;
        else
            return mid;
        mid=(s+e)/2;
    }
}

int main()
{
    // int arr[]={8,1,2,3,4,5,6};
    // cout<<solve(arr,0,8);
    vector<pair<int,int>>v;
    v.push_back({1,2});
    v.push_back({3,4});
    v.push_back({5,6});
    for(auto i :v)
    {
        cout<<i.first<<" "<<i.second<<endl;
    }
    return 0;
}