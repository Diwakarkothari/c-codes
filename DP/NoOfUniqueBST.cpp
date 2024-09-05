#include<iostream>
#include<vector>
using namespace std;
/*
        Another solution is Catalan numbers
        formula-->>
            (2n)!
        --------------
          (n+1)! * n!
*/
class Solution {
public:

    // i-> root node mana hai to
    // total=left*right
    // i ke left mein 1 to (i-1) and right mein (n-i) nodes
    int solve(int n)
    {
        if(n==1 || n==0)
            return 1;
        if(n==2)
            return 2;
        
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            ans+=solve(i-1)*solve(n-i);
        }
        return ans;
    }

    int solveMem(int n,vector<int>& dp)
    {
        if(n==1 || n==0)
            return 1;
        if(n==2)
            return 2;
        
        if(dp[n]!=-1)
            return dp[n];
        
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            ans+=solveMem(i-1,dp)*solveMem(n-i,dp);
        }
        return dp[n] = ans;
    }

    int solveTab(int n)
    {
        vector<int> dp(n+1,0);
        dp[0]=dp[1]=1;

        // i=no. of nodes
        for(int i=2;i<=n;i++)
        {
            int ans=0;
            // j-> kisko root node mana hai
            for(int j=1;j<=i;j++)
            {   
                ans+=dp[j-1]*dp[i-j];
            }
            dp[i]=ans;
        }
        return dp[n];
    }

    int numTrees(int n) {
        // return solve(n);
        // vector<int> dp(n+1,-1);
        // return solveMem(n,dp);
        return solveTab(n);
    }
};