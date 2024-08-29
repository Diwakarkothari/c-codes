#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    
    int solve(vector<vector<int>> mat,int n,int m,int& maxi,int i,int j)
    {
        if(i>=n || j>=m)
            return 0;
        
        int right = solve(mat,n,m,maxi,i,j+1);
        int diag = solve(mat,n,m,maxi,i+1,j+1);
        int down = solve(mat,n,m,maxi,i+1,j);
        
        if(mat[i][j]==1)
        {
            int ans = 1+min(right,min(diag,down));
            maxi=max(maxi,ans);
            return ans;
        }
        else
            return 0;
    }
    
    int solveMem(vector<vector<int>>& mat,int n,int m,int i,int j,
            vector<vector<int>>& dp,int& maxi)
    {
        if(i>=n || j>=m)
            return 0;
            
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int right = solveMem(mat,n,m,i,j+1,dp,maxi);
        int diag = solveMem(mat,n,m,i+1,j+1,dp,maxi);
        int down = solveMem(mat,n,m,i+1,j,dp,maxi);
        
        if(mat[i][j]==1)
        {
            dp[i][j] = 1+min(right,min(diag,down));
            maxi=max(dp[i][j],maxi);
            return dp[i][j];
        }
        else
            return dp[i][j]=0;
    }
    
    int solveTab(vector<vector<int>>& mat,int n,int m,int& maxi)
    {
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                int right = dp[i][j+1];
                int diag = dp[i+1][j+1];
                int down = dp[i+1][j]; 
                
                if(mat[i][j]==1)
                {
                    dp[i][j] = 1+min(right,min(diag,down));
                    maxi=max(dp[i][j],maxi);
                }
                else
                    dp[i][j]=0;
            }
        }
        return dp[0][0];
    }
    int solveTabAndSpaceOptimization(vector<vector<int>>& mat,int n,int m,
                                    int& maxi)
    {
        // vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        vector<int> curr(m+1,0);
        vector<int> next(m+1,0);
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                // curr dp[i]      next dp[i+1]
                int right = curr[j+1];
                int diag = next[j+1];
                int down = next[j]; 
                
                if(mat[i][j]==1)
                {
                    curr[j] = 1+min(right,min(diag,down));
                    maxi=max(curr[j],maxi);
                }
                else
                    curr[j]=0;
            }
            next=curr;
        }
        return next[0];
    }
    
    int solveMore(vector<vector<int>>& mat,int n,int m,
                                    int& maxi)
    {
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                int down = i<n-1?mat[i+1][j]:0;
                int right = j<m-1? mat[i][j+1]:0;
                int diag = i<n-1 and j<m-1? mat[i+1][j+1]:0;
                // if(dp[i][j] == 1)
                if(mat[i][j] == 1){
                    mat[i][j] = 1 + min(down,min(right, diag));
                    maxi = max(mat[i][j],maxi);
                }
            }
        }
        return maxi;
    }
    
    int maxSquare(int n, int m, vector<vector<int>> mat) {
        // code here
        // int maxi=0;
        // solve(mat,n,m,maxi,0,0);
        // return maxi;
        // int maxi=0;
        // vector<vector<int>> dp(n,vector<int>(m,-1));
        // solveMem(mat,n,m,0,0,dp,maxi);
        // return maxi;
        int maxi=0;
        // solveTab(mat,n,m,maxi);
        // solveTabAndSpaceOptimization(mat,n,m,maxi);
        solveMore(mat,n,m,maxi);
        return maxi;
    }
};