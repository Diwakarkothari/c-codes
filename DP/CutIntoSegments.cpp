using namespace std;
#include<bits/stdc++.h>

int solve(int n,int x,int y,int z)
{
	if(n==0)
		return 0;
	 
	if(n<0)
		return INT_MIN;
	
	return max(1+solve(n-x,x,y,z),max(1+solve(n-y,x,y,z),1+solve(n-z,x,y,z)));
}

int solveMem(int n,int x,int y,int z,vector<int>& dp)
{
	if(n==0)
		return 0;
	
	if(n<0)
		return INT_MIN;
	
	if(dp[n]!=-1)
		return dp[n];
	
	int i = max(1+solveMem(n-x,x,y,z,dp),1+solveMem(n-y,x,y,z,dp));
	dp[n] = max(i,1+solveMem(n-z,x,y,z,dp));
	return dp[n];
}

int solveTab(int n,int x,int y,int z)
{
	vector<int> dp(n+1,INT_MIN);
	dp[0]=0;
	for(int i=1;i<=n;i++)
	{
		if(i-x>=0)
			dp[i] = max(dp[i],1+dp[i-x]);
		if(i-y>=0)
			dp[i] = max(dp[i],1+dp[i-y]);
		if(i-z>=0)
			dp[i] = max(dp[i],1+dp[i-z]);
	}
	return dp[n];
}

int cutSegments(int n, int x, int y, int z) {
	// Write your code here.
	
	// int ans = solve(n,x,y,z);
	// vector<int> dp(n+1,-1);
	// int ans = solveMem(n,x,y,z,dp);
	int ans = solveTab(n,x,y,z);
	if(ans<0)
		return 0;
	return ans;
}