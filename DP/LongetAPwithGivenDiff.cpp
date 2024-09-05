#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n=arr.size();
        if(n==1)
            return 1;
        if(n==2 && arr[1]-arr[0]==difference)
            return 2;
        else if(n==2)
            return 1;

        // TLE

        // int res=INT_MIN;
        // for(int i=0;i<n;i++)
        // {
        //     int ans=1;
        //     int f = arr[i];
        //     for(int j=i+1;j<n;j++)
        //     {
        //         if(f+difference==arr[j])
        //         {
        //             ans++;
        //             f=arr[j];
        //         }
        //     }
        //     res=max(res,ans);
        // }
        // return res;

        unordered_map<int,int> m;
        int res=INT_MIN;
        for(int i=0;i<n;i++)
        {
            int temp=arr[i]-difference;
            int ans=0;
            // agar piche ans pada hai to usko use kar lenge
            if(m.count(temp))
            {
                ans=m[temp];
            }
            // present mein update kar lenge
            m[arr[i]]=1+ans;
            res=max(res,m[arr[i]]);
        }

        return res;
    }
};