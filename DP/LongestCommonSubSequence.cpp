#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int solve(string text1,string text2,int i,int j)
    {
        if(i==text1.length() || j==text2.length())
            return 0;
        
        if(text1[i]==text2[j])
            return 1+solve(text1,text2,i+1,j+1);
        else
            return max(solve(text1,text2,i+1,j),
            solve(text1,text2,i,j+1));
    }
    
    int solveMem(string text1,string text2,int i,int j,
    vector<vector<int>>& dp)
    {
        if(i==text1.length() || j==text2.length())
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(text1[i]==text2[j])
            return dp[i][j] = 1+solveMem(text1,text2,i+1,j+1,dp);
        else
            return dp[i][j] = max(solveMem(text1,text2,i+1,j,dp),
            solveMem(text1,text2,i,j+1,dp));
    }

    int solveTheory(string text1,string text2)
    {
        int n=text1.length();
        int m=text2.length();
        vector<vector<int>> arr(n+1,vector<int>(m+1,0));
        int s1=0,s2=0;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(text1[s1]==text2[s2])
                    arr[i][j]=arr[i-1][j-1]+1;
                else
                    arr[i][j]=max(arr[i-1][j],arr[i][j-1]);
                
                s2++;
            }
            s2=0;
            s1++;
        }
        return arr[n][m];
    }

    int solveTab(string text1,string text2)
    {
        int n=text1.length();
        int m=text2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        int s1=0,s2=0;
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(text1[i]==text2[j])
                    dp[i][j] = 1+dp[i+1][j+1];
                else
                    dp[i][j] = max(dp[i+1][j],dp[i][j+1]);
            }
        }
        return dp[0][0];
    }

    int solveOpt(string text1,string text2)
    {
        int n=text1.length();
        int m=text2.length();
        vector<int> next(m+1,0);
        vector<int> curr(m+1,0);
        int s1=0,s2=0;
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(text1[i]==text2[j])
                    curr[j] = 1+next[j+1];
                else
                    curr[j] = max(next[j],curr[j+1]);
            }
            next=curr;
        }
        return next[0];
    }

    int longestCommonSubsequence(string text1, string text2) {
        // return solve(text1,text2,0,0);
        // vector<vector<int>> dp(text1.length()+1,vector<int>(text2.length()+1,-1));
        // return solveMem(text1,text2,0,0,dp);
        // return solveTheory(text1,text2);
        // return solveTab(text1,text2);
        return solveOpt(text1,text2);
    }
};