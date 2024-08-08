#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    int solve(vector<int>& slices,int index,int e,int n)
    {
        if(n==0||index>e)
            return 0;
        
        int incl = slices[index] + solve(slices,index+2,e,n-1);
        int excl = solve(slices,index+1,e,n);
        return max(incl,excl);
    }

    int solveMem(vector<int>& slices,int index,int e,int n,vector<vector<int>>& dp)
    {
        if(n==0||index>e)
            return 0;

        if(dp[index][n]!=-1)
            return dp[index][n];
        
        int incl = slices[index] + solveMem(slices,index+2,e,n-1,dp);
        int excl = solveMem(slices,index+1,e,n,dp);
        return dp[index][n] =  max(incl,excl);
    }

    int solveTab(vector<int>& slices)
    {
        int k = slices.size();
        vector<vector<int>> dp1(k+2,vector<int>(k+2,0));
        for(int i=k-2;i>=0;i--)
        {
            for(int j=1;j<=k/3;j++)
            {
                int incl = slices[i] + dp1[i+2][j-1];
                int excl = dp1[i+1][j];
                dp1[i][j] = max(incl,excl);
            }
        }

        vector<vector<int>> dp2(k+2,vector<int>(k+2,0));
        for(int i=k-1;i>=1;i--)
        {
            for(int j=1;j<=k/3;j++)
            {
                int incl = slices[i] + dp2[i+2][j-1];
                int excl=dp2[i+1][j];
                dp2[i][j] = max(incl,excl);
            }
        }

        return max(dp1[0][k/3],dp2[1][k/3]);
    }

    int solveOpt(vector<int>& slices)
    {
        int k = slices.size();
        // vector<vector<int>> dp1(k+2,vector<int>(k+2,0));
        vector<int> prev1(k+2,0);
        vector<int> curr1(k+2,0);
        vector<int> next1(k+2,0);
        for(int i=k-2;i>=0;i--)
        {
            for(int j=1;j<=k/3;j++)
            {
                int incl = slices[i] + next1[j-1];
                int excl = curr1[j];
                prev1[j] = max(incl,excl);
            }
            next1=curr1;
            curr1=prev1;
        }

        // vector<vector<int>> dp2(k+2,vector<int>(k+2,0));
        vector<int> prev2(k+2,0);
        vector<int> curr2(k+2,0);
        vector<int> next2(k+2,0);
        for(int i=k-1;i>=1;i--)
        {
            for(int j=1;j<=k/3;j++)
            {
                int incl = slices[i] + next2[j-1];
                int excl=curr2[j];
                prev2[j] = max(incl,excl);
            }
            next2=curr2;
            curr2=prev2;
        }

        return max(curr1[k/3],curr2[k/3]);
    }

    int maxSizeSlices(vector<int>& slices) {
        // int n=slices.size();
        // return max(solve(slices,0,n-2,n/3),solve(slices,1,n-1,n/3));
        // vector<vector<int>> dp1(n,vector<int>(n,-1));
        // vector<vector<int>> dp2(n,vector<int>(n,-1));
        // 2 recursive kall jaa rahi hai alag alag isliye 2 dp chahiye
        // return max(solveMem(slices,0,n-2,n/3,dp1),solveMem(slices,1,n-1,n/3,dp2));
        // return solveTab(slices);
        return solveOpt(slices);
    }
};