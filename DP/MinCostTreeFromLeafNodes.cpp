#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    int solve(vector<int>& arr,map<pair<int,int>,int>& m,int l,int r)
    {
        if(l==r)
            return 0;
        
        int ans=INT_MAX;
        for(int i=l;i<r;i++)
        {
            ans=min(ans,m[{l,i}]*m[{i+1,r}]+solve(arr,m,l,i)+solve(arr,m,i+1,r));
        }
        return ans;
    }

    int solveMem(vector<int>& arr,map<pair<int,int>,int>& m,int l,int r,vector<vector<int>>& dp)
    {
        if(l==r)
            return 0;

        if(dp[l][r]!=-1)
            return dp[l][r];
        
        int ans=INT_MAX;
        for(int i=l;i<r;i++)
        {
            ans=min(ans,m[{l,i}]*m[{i+1,r}]+solveMem(arr,m,l,i,dp)+solveMem(arr,m,i+1,r,dp));
        }
        return dp[l][r] = ans;
    }

    int solveTab(vector<int>& arr,map<pair<int,int>,int>& m,int n)
    {
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int l=n-1;l>=0;l--)
        {
            for(int r=0;r<n;r++)
            {
                if(l==r)
                    continue;
                else
                {
                    int ans=INT_MAX;
                    for(int i=l;i<r;i++)
                    {
                        ans=min(ans,m[{l,i}]*m[{i+1,r}]+dp[l][i]+dp[i+1][r]);
                    }
                    dp[l][r] = ans;
                }
            }
        }
        return dp[0][n-1];
    }

    // Best solution SAMAJ NHI AAYA
    int best(vector<int>& arr)
    {
        int n=arr.size();

        // we can solve it using stack
        // if two numbers are there i.e, a,b then to minimize the cost i need to remove the 
        // smaller of a and b so that i can minimize my cost
        stack<int> st;
        st.push(INT_MAX);
        int cost=0;
        for(int i=0;i<n;i++){
            while(st.top()<=arr[i]){
                int x=st.top();
                st.pop();
                cost+=x*min(st.top(),arr[i]);
            }
            st.push(arr[i]);
        }
        while(st.size()>2){
            int x=st.top();
            st.pop();
            cost+=x*st.top();
        }
        return cost;
    }

    int mctFromLeafValues(vector<int>& arr) {
        int n=arr.size();
        if(n==2)
            return arr[0]*arr[1];
        
        // map<pair<int,int>,int> m;
        // for(int i=0;i<n;i++)
        // {
        //     m[{i,i}]=arr[i];
        //     for(int j=i+1;j<n;j++)
        //     {
        //         m[{i,j}]=max(arr[j],m[{i,j-1}]);
        //     }
        // }
        // return solve(arr,m,0,n-1);
        // vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        // return solveMem(arr,m,0,n-1,dp);
        // return solveTab(arr,m,n);
        return best(arr);
    }
};