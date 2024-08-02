#include <bits/stdc++.h>
using namespace std; 

int solve(vector<int>& nums,int n,int ans)
{
	if(n<0)
		return ans;
	
	return max(solve(nums,n-2,ans+nums[n]),solve(nums,n-1,ans));
}

int solve(vector<int>& nums,int n)
{
	if(n<0)
		return 0;
	
	if(n==0)
		return nums[0];

	int incl = solve(nums,n-2)+nums[n];
	int excl = solve(nums,n-1)+0;
	return max(incl,excl);	
}

int solveMem(vector<int>& nums,int n,vector<int>& dp)
{
	if(n<0)
		return 0;
	if(dp[n]!=-1)
		return dp[n];
	dp[n] = max(solveMem(nums,n-2,dp)+nums[n],solveMem(nums,n-1,dp));
	return dp[n];
}

int solveTab(vector<int>& nums)
{
	int n= nums.size();
	vector<int> dp(n,0);
	dp[0]=nums[0];
	for(int i=1;i<=n;i++)
	{
		dp[i] = max(dp[i-2]+nums[i],dp[i-1]);
	}
	return dp[n-1];
}

int solveOptimize(vector<int>& nums)
{
	int n= nums.size();
	int first = 0;
	int second = nums[0];
	for(int i=1;i<n;i++)
	{
		int curr = max(first+nums[i],second);
		first=second;
		second=curr;
	}
	return second;
}

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
	// return solve(nums,nums.size()-1,0);
	// vector<int> dp(nums.size()+1,-1);
	// return solveMem(nums,nums.size()-1,dp);
	// return solveTab(nums);
	return solveOptimize(nums);
}