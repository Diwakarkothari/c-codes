#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    int solve(int index,vector<int>& prices,bool buy,int limit)
    {
        if(index==prices.size())
            return 0;
        if(limit==2)
            return 0;
        
        int profit=0;
        if(buy)
        {
            profit=max(
                -prices[index]+solve(index+1,prices,0,limit),
                0+solve(index+1,prices,1,limit)
            );
        }
        else
        {
            profit=max(
                prices[index]+solve(index+1,prices,1,limit+1),
                0+solve(index+1,prices,0,limit)
            );
        }
        return profit;
    }

    int solveMem(int index,vector<int>& prices,bool buy,int limit,vector<vector<vector<int>>>& dp)
    {
        if(index==prices.size())
            return 0;
        if(limit==2)
            return 0;
        
        if(dp[index][buy][limit]!=-1)
            return dp[index][buy][limit];
        
        int profit=0;
        if(buy)
        {
            profit=max(
                -prices[index]+solveMem(index+1,prices,0,limit,dp),
                0+solveMem(index+1,prices,1,limit,dp)
            );
        }
        else
        {
            profit=max(
                prices[index]+solveMem(index+1,prices,1,limit+1,dp),
                0+solveMem(index+1,prices,0,limit,dp)
            );
        }
        return dp[index][buy][limit] = profit;
    }

    int solveTab(vector<int>& prices)
    {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,0)));
        for(int index=n-1;index>=0;index--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                for(int limit=2;limit>=0;limit--)
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
                            prices[index]+dp[index+1][1][limit+1],
                            0+dp[index+1][0][limit]
                        );
                    }
                    dp[index][buy][limit] = profit;
                }
            }
        }
        return dp[0][1][0];
    }

    int solveOpt(vector<int>& prices)
    {
        int n=prices.size();
        vector<vector<int>> curr(2,vector<int>(3,0));
        vector<vector<int>> next(2,vector<int>(3,0));
        for(int index=n-1;index>=0;index--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                for(int limit=2;limit>=0;limit--)
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
                            prices[index]+next[1][limit+1],
                            0+next[0][limit]
                        );
                    }
                    curr[buy][limit] = profit;
                }
            }
            next=curr;
        }
        return next[1][0];
    }

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // return solve(0,prices,1,0);
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return solveMem(0,prices,1,0,dp);
        // TLE

        // map<pair<int,int>,int> m;
        // int n=prices.size();
        // for(int i=0;i<n;i++)
        // {
        //     int maxdiff=0;
        //     for(int j=i+1;j<n;j++)
        //     {
        //         if(prices[j]>prices[i])
        //         {
        //             maxdiff=prices[j]-prices[i];
        //             m[{i,j}]=maxdiff;
        //         }
        //     }
        // }
        // int maxProfit = 0;
    
        // // Try all possible first transactions and check for a second transaction
        // for (auto &firstTrans : m) 
        // {
        //     int firstBuy = firstTrans.first.first;
        //     int firstSell = firstTrans.first.second;
        //     int firstProfit = firstTrans.second;
            
        //     // Find a second transaction starting after the firstSell
        //     int secondProfit = 0;
        //     for (auto &secondTrans : m) {
        //         int secondBuy = secondTrans.first.first;
        //         if (secondBuy > firstSell) {
        //             secondProfit = max(secondProfit, secondTrans.second);
        //         }
        //     }
            
        //     // Update max profit with the sum of both transactions
        //     maxProfit = max(maxProfit, firstProfit + secondProfit);
        // }
        // return maxProfit;
    }
};