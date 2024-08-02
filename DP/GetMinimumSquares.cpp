#include<iostream>
#include<vector>
#include<climits>
using namespace std;
class Solution{
	public:
	
	int solve(int n)
	{
	    if(n==0)
	        return 0;
	    
	    int mini=n;
	    for(int i=1;i*i<=n;i++)
	    {
	        mini=min(mini,1+solve(n-(i*i)));
	    }
	    return mini;
	}
	
	int solveMem(int n,vector<int>& dp)
	{
	    if(n==0)
	        return 0;
	    
	    if(dp[n]!=-1)
	        return dp[n];
	    int mini=n;
	    for(int i=1;i*i<=n;i++)
	    {
	        mini=min(mini,1+solveMem(n-(i*i),dp));
	    }
	    dp[n] = mini;
	    return dp[n];
	}
	
	int solveTab(int n)
	{
	    vector<int> dp(n+1,INT_MAX);
	    dp[0]=0;
	    for(int j=1;j<=n;j++)
	    {
	        for(int i=1;i*i<=n;i++)
	        {
	            if(j-i*i>=0)
	            dp[j] = min(dp[j],1+dp[j-i*i]);
	        }
	    }
	    return dp[n];
	}
	
	int MinSquares(int n)
	{
	    // Code here
	   // return solve(n);
	   //vector<int> dp(n+1,-1);
	   //return solveMem(n,dp);
	   return solveTab(n);
	}
};