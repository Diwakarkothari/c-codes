#include<vector>
#include<iostream>
#define MOD 1000000007
using namespace std;

long long int solve(int n)
{
    if(n==1)
        return 0;
    
    if(n==2)
    {
        return 1;
    }
    return ((n-1)*((solve(n-1)+solve(n-2))%MOD))%MOD;
}

long long int solveMem(int n,vector<long long int>& dp)
{
    if(n==1)
        return 0;
    if(n==2)
        return 1;
    
    if(dp[n]!=-1)
        return dp[n];
    
    dp[n] = ((n-1)*(solveMem(n-1,dp)+solveMem(n-2,dp)%MOD)%MOD);
    return dp[n];
}

long long int solveTab(int n)
{
    vector<long long int> dp(n+1,0);
    dp[1]=0;
    dp[2]=1;
    for(int i=3;i<=n;i++)
    {
        dp[i] = ((i-1)*((dp[i-1]+dp[i-2])%MOD)%MOD);
    }
    return dp[n];
}

long long int Optimized(int n)
{
    long long int first = 0;
    long long int second = 1;
    for(int i=3;i<=n;i++)
    {
        long long int curr = ((i-1)*((first+second)%MOD)%MOD);
        first=second;
        second=curr;
    }
    return second;
}

long long int countDerangements(int n) {
    // Write your code here.
    // return solve(n);
    // vector<long long int> dp(n+1,-1);
    // return solveMem(n,dp);
    // return solveTab(n);
    return Optimized(n);
}