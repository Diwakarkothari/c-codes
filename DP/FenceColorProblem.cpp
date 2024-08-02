#include <bits/stdc++.h> 
using namespace std;
#define MOD 1000000007

int solve(int n,int k)
{
    if(n==1)
        return k;
        
    if(n==2)
        return k*k;

    return ((solve(n-1,k)+solve(n-2,k))*(k-1))%MOD;
}

int solveMem(int n,int k,vector<int>& dp)
{
    if(n==1)
        return k;
    
    if(n==2)
        return k*k;
    
    if(dp[n]!=-1)
        return dp[n];
    
    dp[n] = (((solveMem(n-1,k,dp)+solveMem(n-2,k,dp))%MOD)*1LL*(k-1))%MOD;
    return dp[n];
}

int solveTab(int n,int k)
{
    vector<int> dp(n+1,-1);
    dp[1]=k;
    dp[2]=k*k;
    for(int i=3;i<=n;i++)
    {
        dp[i] = ((dp[i-1]+dp[i-2])*1LL*(k-1))%MOD;
    }
    return dp[n];
}

int Optimize(int n,int k)
{
    int first=k;
    int second = k*k;
    for(int i=3;i<=n;i++)
    {
        int curr = ((first+second)*1LL*(k-1))%MOD;
        first=second;
        second=curr;
    }
    return second;
}

int numberOfWays(int n, int k) {
    // Write your code here.
    // return solve(n,k)%MOD;
    // vector<int> dp(n+1,-1);
    // return solveMem(n,k,dp)%MOD;
    // return solveTab(n,k)%MOD;
    return Optimize(n,k);
}
