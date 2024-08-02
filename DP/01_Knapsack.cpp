#include <bits/stdc++.h> 
using namespace std;

int solve(vector<int>& weight, vector<int>& value, int n, int maxWeight)
{
	if(n==0){
		if(weight[0] <= maxWeight)
			return value[0];
		else
			return 0;
	}

	int incl=0;
	if(maxWeight-weight[n]>=0)
		incl = value[n]+solve(weight,value,n-1,maxWeight-weight[n]);

	int excl = solve(weight,value,n-1,maxWeight);
	return max(incl,excl);
}

int solveTab(vector<int>& weight, vector<int>& value, int n, int maxWeight)
{
	vector<vector<int>> dp(n,vector<int>(maxWeight+1,0));

	for(int i=weight[0];i<=maxWeight;i++)
	{ // agar weight kam hoga to huri row update karenge
		if(weight[0]<=maxWeight)
			dp[0][i]=value[0];
		else // weight jyada hai to puri row 0 ho jayegi
			dp[0][i]=0;
	}

	for(int i=1;i<n;i++)
	{
		for(int j=0;j<=maxWeight;j++)
		{
			int incl=0;
			if(j-weight[i]>=0)
				incl = value[i]+dp[i-1][j-weight[i]];
			
			int excl = dp[i-1][j];
			dp[i][j]=max(incl,excl);
		}
	}
	return dp[n-1][maxWeight];
}

int solveMem(vector<int>& weight, vector<int>& value, int n, int maxWeight,
				vector<vector<int>>& dp)
{
	if(n==0){
		if(weight[0] <= maxWeight)
			return value[0];
		else
			return 0;
	}

	if(dp[n][maxWeight]!=-1)
		return dp[n][maxWeight];

	int incl=0;
	if(maxWeight-weight[n]>=0)
		incl = value[n]+solveMem(weight,value,n-1,maxWeight-weight[n],dp);

	int excl = solveMem(weight,value,n-1,maxWeight,dp);
	dp[n][maxWeight] = max(incl,excl);
	return dp[n][maxWeight];
}

int Optimized(vector<int>& weight, vector<int>& value, int n, int maxWeight)
{
	vector<int> first(maxWeight+1,0);
	vector<int> second(maxWeight+1,0);

	for(int i=weight[0];i<=maxWeight;i++)
	{ // agar weight kam hoga to huri row update karenge
		if(weight[0]<=maxWeight)
			first[i]=value[0];
		else // weight jyada hai to puri row 0 ho jayegi
			first[i]=0;
	}

	for(int i=1;i<n;i++)
	{
		for(int j=0;j<=maxWeight;j++)
		{
			int incl=0;
			if(j-weight[i]>=0)
				incl = value[i]+first[j-weight[i]];
			
			int excl = first[j];
			second[j]=max(incl,excl);
		}
		first=second;
	}
	return first[maxWeight];
}


int MoreOptimized(vector<int>& weight, vector<int>& value, int n, int maxWeight)
{
	vector<int> first(maxWeight+1,0);

	for(int i=weight[0];i<=maxWeight;i++)
	{ // agar weight kam hoga to huri row update karenge
		if(weight[0]<=maxWeight)
			first[i]=value[0];
		else // weight jyada hai to puri row 0 ho jayegi
			first[i]=0;
	}

	for(int i=1;i<n;i++)
	{
		for(int j=maxWeight;j>=0;j--)
		{
			int incl=0;
			if(j-weight[i]>=0)
				incl = value[i]+first[j-weight[i]];
			
			int excl = first[j];
			first[j]=max(incl,excl);
		}
	}
	return first[maxWeight];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	// return solve(weight,value,n-1,maxWeight);
	// vector<vector<int>> dp(n,vector<int>(maxWeight+1,-1));
	// return solveMem(weight,value,n-1,maxWeight,dp);
	// return solveTab(weight,value,n,maxWeight);
	// return Optimized(weight,value,n,maxWeight);
    return MoreOptimized(weight,value,n,maxWeight);
}