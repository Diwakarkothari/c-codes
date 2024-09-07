#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    int solve(int index,vector<int>& prices,int fee,bool buy)
    {
        if(index==prices.size())
            return 0;
        
        int profit=0;
        if(buy)
        {
            profit=max(
                -prices[index]+solve(index+1,prices,fee,0),
                0+solve(index+1,prices,fee,1)
            );
        }
        else
        {
            profit=max(
                prices[index]+solve(index+1,prices,fee,1)-fee,
                0+solve(index+1,prices,fee,0)
            );
        }
        return profit;
    }

    int solveMem(int index,vector<int>& prices,int fee,bool buy,vector<vector<int>>& dp)
    {
        if(index==prices.size())
            return 0;

        if(dp[index][buy]!=-1)
            return dp[index][buy];
        
        int profit=0;
        if(buy)
        {
            profit=max(
                -prices[index]+solveMem(index+1,prices,fee,0,dp),
                0+solveMem(index+1,prices,fee,1,dp)
            );
        }
        else
        {
            profit=max(
                prices[index]+solveMem(index+1,prices,fee,1,dp)-fee,
                0+solveMem(index+1,prices,fee,0,dp)
            );
        }
        return dp[index][buy] = profit;
    }

    int solveTab(vector<int>& prices, int fee)
    {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(3,0));   
        for(int index=n-1;index>=0;index--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                int profit=0;
                if(buy)
                {
                    profit=max(
                        -prices[index]+dp[index+1][0],
                        0+dp[index+1][1]
                    );
                }
                else
                {
                    profit=max(
                        prices[index]+dp[index+1][1]-fee,
                        0+dp[index+1][0]
                    );
                }
                dp[index][buy] = profit;
            }
        }    
        return dp[0][1];
    }

    int solveOpt(vector<int>& prices, int fee)
    {
        int n=prices.size();
        vector<int> next(3,0);
        vector<int> curr(3,0);   
        for(int index=n-1;index>=0;index--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                int profit=0;
                if(buy)
                {
                    profit=max(
                        -prices[index]+next[0],
                        0+next[1]
                    );
                }
                else
                {
                    profit=max(
                        prices[index]+next[1]-fee,
                        0+next[0]
                    );
                }
                curr[buy] = profit;
            }
            next=curr;
        }    
        return next[1];
    }

    int maxProfit(vector<int>& prices, int fee) {
        // return solve(0,prices,fee,1);
        // int n=prices.size();
        // vector<vector<int>> dp(n+1,vector<int>(3,-1));
        // return solveMem(0,prices,fee,1,dp);
        // return solveTab(prices,fee);
        return solveOpt(prices,fee);
    }
};