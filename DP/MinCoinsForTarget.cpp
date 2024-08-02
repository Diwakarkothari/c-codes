#include<iostream>
#include<vector>
using namespace std;

#include <bits/stdc++.h> 

int solve(vector<int>& num,int target,int n)
{
    if(target==0)
        return 0;

    if(target<0)
        return INT_MAX;
    
    int mini=INT_MAX;
    for(int i=0;i<n;i++)
    {
        int temp=solve(num,target-num[i],n);
        if(temp!=INT_MAX)
            mini=min(mini,1+temp);
    }
    return mini;
}

int solveMem(vector<int>& num,int target,vector<int>& dp)
{
    if(target==0)
        return 0;

    if(target<0)
        return INT_MAX;
    
    if(dp[target]!=-1)
        return dp[target];

    int mini=INT_MAX;
    for(int i=0;i<num.size();i++)
    {
        int temp=solveMem(num,target-num[i],dp);
        if(temp!=INT_MAX)
            mini=min(mini,1+temp);
    }
    dp[target]=mini;
    return dp[target];
}

int solveTab(vector<int>& num,int x)
{
    vector<int> dp(x+1,INT_MAX);
    dp[0]=0;
    for(int i=1;i<=x;i++)
    {
        for(int j=0;j<num.size();j++)
        {
            if(i-num[j] >= 0 && dp[i-num[j]]!=INT_MAX)
                dp[i] = min(dp[i], 1 + dp[i-num[j]]);
        }
    }
    return dp[x];
}

int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    // int ans =  solve(num,x,num.size());


    // apna x variable hai isliye uska array banayenge
    // vector<int> dp(x+1,-1);
    // int ans = solveMem(num,x,dp);
    int ans = solveTab(num,x);
    if(ans==INT_MAX)
        return -1;
    return ans;
}