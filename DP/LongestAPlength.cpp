#include<bits/stdc++.h>
using namespace std;
int solve(int i,int diff,vector<int>& arr)
    {
        if(i<0)
            return 0;
        
        int ans=0;
        for(int j=i-1;j>=0;j--)
        {
            if(arr[i]-arr[j]==diff)
            {
                ans=max(ans,1+solve(j,diff,arr));
            }
        }
        return ans;
    }
    
    // TLE
    int solveMem(int i,int diff,vector<int>& arr,unordered_map<int,int> dp[])
    {
        if(i<0)
            return 0;
            
        if(dp[i].count(diff))
            return dp[i][diff];
        
        int ans=0;
        for(int j=i-1;j>=0;j--)
        {
            if(arr[i]-arr[j]==diff)
            {
                ans=max(ans,1+solve(j,diff,arr));
            }
        }
        return dp[i][diff] = ans;
    }
    
    int solveTab(vector<int>& arr)
    {
        int ans=0;
        int n=arr.size();
        unordered_map<int,int> dp[n+1];
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                int diff=arr[i]-arr[j];
                int cnt=1;
                
                // check if already present
                if(dp[j].count(diff))
                    cnt=dp[j][diff];
                    
                dp[i][diff]=1+cnt;
                ans=max(ans,dp[i][diff]);
            }
        }
        return ans;
    }
  
    int lengthOfLongestAP(vector<int>& arr) {
        // code here
        int n=arr.size();
        if(n==1)
            return 1;
        if(n==2)
            return 2;
        
        // MY WRONG APPROACH
        
        // unordered_map<int,int> m;
        // int n=arr.size();
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=i+1;j<n;j++)
        //     {
        //         int diff = arr[j]-arr[i];
        //         m[diff]++;
        //     }
        // }
        // int freq=INT_MIN;
        // int diff;
        // for(auto i : m)
        // {
        //     if(i.second>freq)
        //     {
        //         freq=i.second;
        //         diff=i.first;
        //     }
        // }
        
        // unordered_set<int> s;
        // for(int i=0;i<n;i++)
        // {
        //     s.insert(arr[i]);
        // }
        
        // int count=1;
        // for(int i=0;i<n;i++)
        // {
        //     int sum=arr[i]+diff;
        //     if(s.find(sum)!=s.end())
        //     {
        //         count++;
        //     }
        // }
        // return count;
        
        // unordered_map<int,int> dp[n+1];
        // int ans=0;
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=i+1;j<n;j++)
        //     {
        //         // ans=max(ans,2+solve(i,arr[j]-arr[i],arr));
        //         ans=max(ans,2+solveMem(i,arr[j]-arr[i],arr,dp));
        //     }
        // }
        // return ans;
        
        return solveTab(arr);
        
    }