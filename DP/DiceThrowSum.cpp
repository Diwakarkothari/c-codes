#include <bits/stdc++.h>
using namespace std;
long long solve(int m, int n, int x)
{
    if (x < 0)
        return 0;
    // target mil gya pr dice bache hai
    if (x == 0 && n != 0)
        return 0;
    // dice khatam pr target bacha hai
    if (n == 0 && x != 0)
        return 0;

    if (x == 0 && n == 0)
        return 1;

    long long ans = 0;
    for (int i = 1; i <= m; i++)
    {
        ans += solve(m, n - 1, x - i);
    }
    return ans;
}

long long solveMem(int m, int n, int x, vector<vector<long long>> &dp)
{
    if (x < 0)
        return 0;
    // target mil gya pr dice bache hai
    if (x == 0 && n != 0)
        return 0;
    // dice khatam pr target bacha hai
    if (n == 0 && x != 0)
        return 0;

    if (x == 0 && n == 0)
        return 1;

    if (dp[n][x] != -1)
        return dp[n][x];

    long long ans = 0;
    for (int i = 1; i <= m; i++)
    {
        ans += solveMem(m, n - 1, x - i, dp);
    }
    return dp[n][x] = ans;
}

long long solveTab(int m, int n, int x)
{
    vector<vector<long long>> dp(n + 1, vector<long long>(x + 1, 0));
    dp[0][0] = 1;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= x; j++)
        {
            for (int k = 1; k <= m; k++)
            {
                if (i - 1 >= 0 && j - k >= 0)
                    dp[i][j] += dp[i - 1][j - k];
            }
        }
    }
    return dp[n][x];
}

long long solveOpt(int m, int n, int x)
{
    vector<long long> pre(x + 1, 0);
    pre[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        vector<long long> curr(x + 1, 0);
        for (int j = 1; j <= x; j++)
        {
            for (int k = 1; k <= m; k++)
            {
                if (j - k >= 0)
                    curr[j] += pre[j - k];
            }
        }
        pre = curr;
    }
    return pre[x];
}

long long noOfWays(int m, int n, int x)
{
    // code here
    // vector<vector<long long>> dp(n+1,vector<long long>(x+1,-1));
    // return solve(m,n,x);
    // return solveMem(m,n,x,dp);
    // return solveTab(m,n,x);
    return solveOpt(m, n, x);
}