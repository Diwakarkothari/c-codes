#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(vector<int>& obstacles,int index,int lane)
    {
        if(index==obstacles.size())
            return 0;

        if(obstacles[index+1]!=lane)
            return 0+solve(obstacles,index+1,lane);
        else
        {
            int ans = INT_MAX;
            for(int i=1;i<=3;i++)
            {
                if(lane!=i && obstacles[index]!=i)
                    ans=min(ans,1+solve(obstacles,index,i));
            }
            return ans;
        }
    }

    int solveMem(vector<int>& obstacles,int index,int lane,vector<vector<int>>& dp)
    {
        if(index==obstacles.size()-1)
            return 0;

        if(dp[lane][index]!=-1)
            return dp[lane][index];

        if(index + 1 < obstacles.size() && obstacles[index+1]!=lane)
            return 0+solveMem(obstacles,index+1,lane,dp);
        else
        {
            int ans = INT_MAX;
            for(int i=1;i<=3;i++)
            {
                if(lane!=i && obstacles[index]!=i)
                    ans=min(ans,1+solveMem(obstacles,index,i,dp));
            }
            dp[lane][index] = ans;
            return dp[lane][index];
        }
    }

    int solveTab(vector<int>& obstacles)
    {
        int n=obstacles.size();
        vector<vector<int>> dp(4,vector<int>(n,INT_MAX));
        for(int i=0;i<4;i++)
            dp[i][n-1]=0;
        
        for(int index=n-2;index>=0;index--)
        {
            for(int lane=1;lane<=3;lane++)
            {
                if(obstacles[index+1]!=lane)
                    dp[lane][index]=dp[lane][index+1];
                else
                {
                    int ans = INT_MAX;
                    for(int i=1;i<=3;i++)
                    {
                        if(lane!=i && obstacles[index]!=i)
                            ans=min(ans,1+dp[i][index+1]);
                    }
                    dp[lane][index] = ans;
                }
            }
        }
        return min(dp[2][0],min(1+dp[1][0],1+dp[3][0]));

    }

    int solveOptimize(vector<int>& obstacles)
    {
        vector<int> curr(4,INT_MAX);
        vector<int> next(4,INT_MAX);   
        for(int i=0;i<4;i++)
            next[i]=0;

        int n=obstacles.size();

        for(int index=n-2;index>=0;index--)
        {
            for(int lane=1;lane<=3;lane++)
            {
                if(obstacles[index+1]!=lane)
                    curr[lane]=next[lane];
                else
                {
                    int ans = INT_MAX;
                    for(int i=1;i<=3;i++)
                    {
                        if(lane!=i && obstacles[index]!=i)
                            ans=min(ans,1+next[i]);
                    }
                    curr[lane] = ans;
                }
            }
            next=curr;
        }
        return min(next[2],min(1+next[1],1+next[3]));
    }

    int minSideJumps(vector<int>& obstacles) {
        // return solve(obstacles,0,2);
        // int n=obstacles.size();
        // vector<vector<int>> dp(4,vector<int>(n,-1));
        // return solveMem(obstacles,0,2,dp);
        // return solveTab(obstacles);
        return solveOptimize(obstacles);
    }
};