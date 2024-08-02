#include <bits/stdc++.h> 
using namespace std; 

long long int solve(vector<int>& arr,int e,int s)
{
    if(e<s)
        return 0;
    
    if(e==s)
        return arr[e];
    
    return max(arr[e]+solve(arr,e-2,s),solve(arr,e-1,s));
}

long long int solveMem(vector<int>& arr,int e,int s,vector<long long int>& dp)
{
    if(e<s)
        return 0;
    
    if(e==s)
        return arr[s];

    if(dp[e]!=-1)
        return dp[e];
    
    dp[e] = max(arr[e]+solveMem(arr,e-2,s,dp),solveMem(arr,e-1,s,dp));
    return dp[e];
}

long long int solveTab(vector<int>& arr,int n)
{
    vector<long long int> dp(n,0);
    dp[0]=arr[0];
    dp[1] = max(arr[0],arr[1]);
    for(int i=2;i<n;i++)
    {
        dp[i] = max(dp[i-1],dp[i-2]+arr[i]);
    }
    return dp[n-1]; 
}

long long int solveOptimize(vector<int>& nums)
{
	int n= nums.size();
	long long int first = 0;
	long long int second = nums[0];
	for(int i=1;i<n;i++)
	{
		long long int curr = max(first+nums[i],second);
		first=second;
		second=curr;
	}
	return second;
}

long long int houseRobber(vector<int>& valueInHouse)
{
    // Write your code here.
    int n= valueInHouse.size();
    if(n==1)
        return valueInHouse[0];
    // vector<long long int> dp1(n,-1);
    // vector<long long int> dp2(n,-1);
    // return max(solve(valueInHouse,n-1,1),solve(valueInHouse,n-2,0));
    // return max(solveMem(valueInHouse,n-1,1,dp1),solveMem(valueInHouse,n-2,0,dp2));
    vector<int> arr1;
    vector<int> arr2;
    for(int i=0;i<n;i++)
    {
        if(i==0)
            arr1.push_back(valueInHouse[i]);
        else if(i==n-1)
            arr2.push_back(valueInHouse[i]);
        else
        {
            arr1.push_back(valueInHouse[i]);
            arr2.push_back(valueInHouse[i]);
        }
    }
    // return max(solveTab(arr1,n-1),solveTab(arr2,n-1));
    return max(solveOptimize(arr1),solveOptimize(arr2));
}