#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    int solve(int s,int e,int n)
    {
        if(s<1)
            return 0;
        if(e>n)
            return 0;
        if(s>=e)
            return 0;
        int ans=INT_MAX;
        for(int i=s;i<=e;i++)
        {
            ans=min(ans,i+max(solve(s,i-1,n),solve(i+1,e,n)));
        }
        return ans;
    }

    int solveMem(int s,int e,int n,vector<vector<int>>& dp)
    {
        if(s<1)
            return 0;
        if(e>n)
            return 0;
        if(s>=e)
            return 0;

        if(dp[s][e]!=-1)
            return dp[s][e];

        int ans=INT_MAX;
        for(int i=s;i<=e;i++)
        {
            ans=min(ans,i+max(solveMem(s,i-1,n,dp),solveMem(i+1,e,n,dp)));
        }
        return dp[s][e] = ans;
    }

    // start 1 se n jaa raha tha
    // end n se 1 jaa raha tha
    // tabulation mein ulta karenge
    int solveTab(int n)
    {
        vector<vector<int>> dp(n+2,vector<int>(n+2,0));
        for(int s=n;s>=1;s--)
        {
            for(int e=1;e<=n;e++)
            {
                if(s==e)
                    continue;
                else
                {
                    int ans=INT_MAX;
                    for(int i=s;i<=e;i++)
                    {
                        ans=min(ans,i+max(dp[s][i-1],dp[i+1][e]));
                    }
                    dp[s][e]=ans;
                }
            }
        }
        return dp[1][n];
    }

    int getMoneyAmount(int n) {
        if(n==1)
            return 0;
        if(n==2)
            return 1;
        // return solve(1,n,n);
        // vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        // return solveMem(1,n,n,dp);
        return solveTab(n);
    }
};