#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int solve(vector<int>& cardPoints,int s,int e,int k)
    {
        if(k==0 || s>e)
            return 0;
        
        int start = cardPoints[s]+solve(cardPoints,s+1,e,k-1);
        int end = cardPoints[e] + solve(cardPoints,s,e-1,k-1);
        return max(start,end);
    }

    int solveMem(vector<int>& cardPoints,int s,int e,int k,vector<vector<int>>& dp)
    {
        if(k==0 || s>e)
            return 0;

        if(dp[s][e]!=-1)
            return dp[s][e];
        
        int start = cardPoints[s]+solveMem(cardPoints,s+1,e,k-1,dp);
        int end = cardPoints[e] + solveMem(cardPoints,s,e-1,k-1,dp);
        return dp[s][e] = max(start,end);
    }

    int solveTab(vector<int>& cardPoints,int k)
    {
        int n = cardPoints.size();

        vector<vector<int>> dp(k+1, vector<int>(k+1, 0));

        for (int i = 0; i <= k; i++) 
        {
            for (int j = 0; j <= k - i; j++) 
            {
                if (i > 0) 
                    dp[i][j] = max(dp[i][j], dp[i-1][j] + cardPoints[i-1]);
                if (j > 0) 
                    dp[i][j] = max(dp[i][j], dp[i][j-1] + cardPoints[n-j]);
            }
        }
        int maxScore = 0;
        for (int i = 0; i <= k; i++) 
        {
            maxScore = max(maxScore, dp[i][k-i]);
        }
        return maxScore;
    }

    int maxScore(vector<int>& cardPoints, int k) {
        // return solve(cardPoints,0,cardPoints.size()-1,k);
        int n = cardPoints.size();
        // vector<vector<int>> dp(n,vector<int>(n,-1));
        // return solveMem(cardPoints,0,n-1,k,dp);
        // return solveTab(cardPoints,k);

        int sum=0;
        for(int i=0;i<k;i++)
            sum+=cardPoints[i];
        
        int back=n-1,front = k-1;
        int maxi=sum;
        while(front>=0)
        {
            sum+=cardPoints[back]-cardPoints[front];
            maxi=max(maxi,sum);
            front--;
            back--;
        }
        return maxi;

    }
};