#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int mini=arr[n-1]-arr[0];
        // unordered_map<int,int> m;
        // m[arr[0]]=0;
        // for(int i=1;i<n;i++)
        // {
        //     m[arr[i]]=i;
        //     mini= min(mini,arr[i]-arr[i-1]);
        // }
        // for(int i=0;i<n;i++)
        // {
        //     if(m.count(arr[i]+mini))
        //         ans.push_back({arr[i],arr[i]+mini});
        // }
        for(int i=1;i<n;i++)
        {
            mini= min(mini,arr[i]-arr[i-1]);
        }
        for(int i=1;i<n;i++)
        {
            if(arr[i]-arr[i-1]==mini)
                ans.push_back({arr[i-1],arr[i]});
        }
        return ans;
    }
};