#include<bits/stdc++.h>
using namespace std;

bool solve(int arr[],int n,int sum1,int sum2)
    {
        if(n<0 && sum1==sum2)
            return true;
        else if(n<0)
            return false;
        
        return (solve(arr,n-1,sum1+arr[n],sum2) 
        || solve(arr,n-1,sum1,sum2+arr[n]));
        
    }
    
    bool solvehalf(int arr[],int n,int tar)
    {
        if(tar<0 || n<0)
            return false;
        
        if(tar==0)
            return true;
        
        return (solvehalf(arr,n-1,tar) 
        || solvehalf(arr,n-1,tar-arr[n]));
    }
    
    bool solveMem(int arr[],int n,int tar,vector<vector<int>>& dp)
    {
        if(tar<0 || n<0)
            return false;
        
        if(tar==0)
            return true;
            
        if(dp[n][tar]!=-1)
            return dp[n][tar];
        
        return dp[n][tar] = (solveMem(arr,n-1,tar,dp) 
        || solveMem(arr,n-1,tar-arr[n],dp));
    }
    
    bool solveTab(int arr[],int N,int tar)
    {
        vector<vector<int>> dp(N+1,vector<int>(tar+1,0));
        
        for(int i=0;i<=N;i++)
            dp[i][0]=1;
        
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=tar;j++)
            {
                if(j-arr[i-1]>=0)
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        return dp[N][tar];
    }
    
    bool solveOpt(int arr[],int N,int tar)
    {
        vector<int> pre(tar+1,0);
        
        pre[0]=1;
        
        for(int i=1;i<=N;i++)
        {
            vector<int> curr(tar+1,0);
            for(int j=1;j<=tar;j++)
            {
                if(j-arr[i-1]>=0)
                    curr[j] = pre[j] || pre[j-arr[i-1]];
                else
                    curr[j]=pre[j];
            }
            pre=curr;
        }
        return pre[tar];
    }

    int equalPartition(int N, int arr[])
    {
        // METHOD-1
        
        // int sum1=0,sum2=0;
        // if(solve(arr,N-1,sum1,sum2))
        //     return 1;
        // else
        //     return 0;
        
        // METHOD-2
        
        // int sum=0;
        // for(int i=0;i<N;i++)
        //     sum+=arr[i];
        
        // if(sum%2!=0)
        //     return 0;
        // else
        //     return solvehalf(arr,N-1,sum/2);
        
        int sum=0;
        for(int i=0;i<N;i++)
            sum+=arr[i];
        
        if(sum%2!=0)
            return 0;
        else
        {
            // vector<vector<int>> dp(N+1,
            // vector<int>(sum/2+1,-1));
            // return solveMem(arr,N-1,sum/2,dp);
            // return solveTab(arr,N,sum/2);
            return solveOpt(arr,N,sum/2);
        }
    }