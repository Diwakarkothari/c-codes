#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    
    int solve(int a[],int n,int curr,int pre)
    {
        if(curr==n)
            return 0;
        
        // include wala case
        int incl=0;
        if(pre==-1 || a[curr] > a[pre])
            incl = 1+solve(a,n,curr+1,curr);
        // exclude wala case
        int excl = solve(a,n,curr+1,pre);
        return max(incl,excl);
    }
    
    int solveMem(int a[],int n,int curr,int pre,vector<vector<int>>& dp)
    {
        if(curr==n)
            return 0;
            
            // +1 if pre==-1 (valid index bananae ke liye)
        if(dp[curr][pre+1]!=-1)
            return dp[curr][pre+1];
        
        // include wala case
        int incl=0;
        if(pre==-1 || a[curr] > a[pre])
            incl = 1+solveMem(a,n,curr+1,curr,dp);
        // exclude wala case
        int excl = solveMem(a,n,curr+1,pre,dp);
        return dp[curr][pre+1] = max(incl,excl);
    }
    
    int solveTab(int a[],int n)
    {
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int curr=n-1;curr>=0;curr--)
        {
            for(int pre=curr-1;pre>=-1;pre--)
            {
                int incl=0;
                if(pre==-1 || a[curr] > a[pre])
                    incl = 1+dp[curr+1][curr+1];
                    // exclude wala case
                int excl = dp[curr+1][pre+1];
                dp[curr][pre+1] = max(incl,excl);
            } 
        }
        return dp[0][0];
    }
    
    int solveOpt(int a[],int n)
    {
        vector<int> c(n+1,0),next(n+1,0);
        for(int curr=n-1;curr>=0;curr--)
        {
            for(int pre=curr-1;pre>=-1;pre--)
            {
                int incl=0;
                if(pre==-1 || a[curr] > a[pre])
                    incl = 1+next[curr+1];
                    // exclude wala case
                int excl = next[pre+1];
                c[pre+1] = max(incl,excl);
            } 
            next=c;
        }
        return c[0];
    }
    
    int solveDPwithBinarySearch(int a[],int n)
    {
        if(n==0)
            return 0;
        
        vector<int> ans;
        ans.push_back(a[0]);
        // time complexity = O(NlogN)
        for(int i=1;i<n;i++)
        {
            if(a[i] > ans.back())
                ans.push_back(a[i]);
            else
            {
                // Binary search lagata hai to O(logN)
                int index = lower_bound(ans.begin(),ans.end(),
                        a[i])-ans.begin();
                ans[index]=a[i];
            }
        }
        return ans.size();
    }
    
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code here
    //   return solve(a,n,0,-1);
        // vector<vector<int>> dp(n,vector<int>(n+1,-1));
        // return solveMem(a,n,0,-1,dp);
        // return solveTab(a,n);
        // return solveOpt(a,n);
        return solveDPwithBinarySearch(a,n);
    }
};