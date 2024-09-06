#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    int solve(int index,vector<int>& prices,bool buy,int limit,int k)
    {
        if(index==prices.size())
            return 0;
        if(limit==k)
            return 0;
        
        int profit=0;
        if(buy)
        {
            profit=max(
                -prices[index]+solve(index+1,prices,0,limit,k),
                0+solve(index+1,prices,1,limit,k)
            );
        }
        else
        {
            profit=max(
                prices[index]+solve(index+1,prices,1,limit+1,k),
                0+solve(index+1,prices,0,limit,k)
            );
        }
        return profit;
    }

    int solveMem(int index,vector<int>& prices,bool buy,int limit,vector<vector<vector<int>>>& dp,int k)
    {
        if(index==prices.size())
            return 0;
        if(limit==k)
            return 0;
        
        if(dp[index][buy][limit]!=-1)
            return dp[index][buy][limit];
        
        int profit=0;
        if(buy)
        {
            profit=max(
                -prices[index]+solveMem(index+1,prices,0,limit,dp,k),
                0+solveMem(index+1,prices,1,limit,dp,k)
            );
        }
        else
        {
            profit=max(
                prices[index]+solveMem(index+1,prices,1,limit+1,dp,k),
                0+solveMem(index+1,prices,0,limit,dp,k)
            );
        }
        return dp[index][buy][limit] = profit;
    }

    int solveTab(vector<int>& prices,int k)
    {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        for(int index=n-1;index>=0;index--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                for(int limit=1;limit<=k;limit++)
                {
                    int profit=0;
                    if(buy)
                    {
                        profit=max(
                            -prices[index]+dp[index+1][0][limit],
                            0+dp[index+1][1][limit]
                        );
                    }
                    else
                    {
                        profit=max(
                            prices[index]+dp[index+1][1][limit-1],
                            0+dp[index+1][0][limit]
                        );
                    }
                    dp[index][buy][limit] = profit;
                }
            }
        }
        return dp[0][1][k];
    }

    int solveOpt(vector<int>& prices,int k)
    {
        int n=prices.size();
        vector<vector<int>> curr(2,vector<int>(k+1,0));
        vector<vector<int>> next(2,vector<int>(k+1,0));
        for(int index=n-1;index>=0;index--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                for(int limit=1;limit<=k;limit++)
                {
                    int profit=0;
                    if(buy)
                    {
                        profit=max(
                            -prices[index]+next[0][limit],
                            0+next[1][limit]
                        );
                    }
                    else
                    {
                        profit=max(
                            prices[index]+next[1][limit-1],
                            0+next[0][limit]
                        );
                    }
                    curr[buy][limit] = profit;
                }
            }
            next=curr;
        }
        return next[1][k];
    }

// operation op even pe buy odd pe sell 
// 0 pe buy 1 pe sell 2 pe buy 3 pe sell
    int solve2(int index,int op,int k,vector<int>& prices)
    {
        if(index==prices.size())
            return 0;
        if(op==2*k)
            return 0;
        
        int profit=0;
        if(op%2==0)
        {
            profit=max(
                -prices[index]+solve2(index+1,op+1,k,prices),
                0+solve2(index+1,op,k,prices)
            );
        }
        else
        {
            profit=max(
                prices[index]+solve2(index+1,op+1,k,prices),
                0+solve2(index+1,op,k,prices)
            );
        }
        return profit;
    }

    int solve2Mem(int index,int op,int k,vector<int>& prices,vector<vector<int>>& dp)
    {
        if(index==prices.size())
            return 0;
        if(op==2*k)
            return 0;

        if(dp[index][op]!=-1)
            return dp[index][op];
        
        int profit=0;
        if(op%2==0)
        {
            profit=max(
                -prices[index]+solve2Mem(index+1,op+1,k,prices,dp),
                0+solve2Mem(index+1,op,k,prices,dp)
            );
        }
        else
        {
            profit=max(
                prices[index]+solve2Mem(index+1,op+1,k,prices,dp),
                0+solve2Mem(index+1,op,k,prices,dp)
            );
        }
        return dp[index][op] = profit;
    }

    int solve2Tab(int k,vector<int>& prices)
    {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2*k+2,0));
        for(int index=n-1;index>=0;index--)
        {
            for(int op=2*k;op>=0;op--)
            {
                int profit=0;
                if(op%2==0)
                {
                    profit=max(
                        -prices[index]+dp[index+1][op+1],
                        0+dp[index+1][op]
                    );
                }
                else
                {
                    profit=max(
                        prices[index]+dp[index+1][op+1],
                        0+dp[index+1][op]
                    );
                }
                dp[index][op] = profit;
            }
        }
        return dp[0][0];
    }

    int solve2Opt(int k,vector<int>& prices)
    {
        int n=prices.size();
        vector<int> next(2*k+2,0);
        vector<int> curr(2*k+2,0);
        for(int index=n-1;index>=0;index--)
        {
            for(int op=2*k;op>=0;op--)
            {
                int profit=0;
                if(op%2==0)
                {
                    profit=max(
                        -prices[index]+next[op+1],
                        0+next[op]
                    );
                }
                else
                {
                    profit=max(
                        prices[index]+next[op+1],
                        0+next[op]
                    );
                }
                curr[op] = profit;
            }
            next=curr;
        }
        return next[0];
    }

    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        // return solve(0,prices,1,0,k);
        // vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        // return solveMem(0,prices,1,0,dp,k);
        // return solveTab(prices,k);
        // return solveOpt(prices,k);


        // 3D DP -->> 2D DP
        // vector<vector<int>> dp(n+1,vector<int>(2*k+1,-1));
        // return solve2(0,0,k,prices);
        // return solve2Mem(0,0,k,prices,dp);
        // return solve2Tab(k,prices);
        return solve2Opt(k,prices);
    }
};