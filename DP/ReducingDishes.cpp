#include<bits/stdc++.h>
using namespace std;

//   MY SOLUTION AND ACCEPTED ALSO
class Solution1 {
public:
    bool check(stack<int>& p,int& maxi)
    {
        int sum=0;
        stack<int> temp;
        int i=1;
        while(!p.empty())
        {
            int top = p.top();
            temp.push(top);
            p.pop();
            sum+=i*top;
            i++;
        }
        if(sum > maxi)
        {
            maxi=sum;
            while(!temp.empty())
            {
                p.push(temp.top());
                temp.pop();
            }
            return true;
        }
        else
            return false;
    }

    int maxSatisfaction(vector<int>& satisfaction) {
        vector<int> pos,neg;
        for(int i=0;i<satisfaction.size();i++)
        {
            if(satisfaction[i]<0)
                neg.push_back(satisfaction[i]);
            else
                pos.push_back(satisfaction[i]);
        }

        int maxi=0;
        if(neg.size()==0)
        {
            sort(pos.begin(),pos.end());
            for(int i=1;i<=pos.size();i++)
            {
                maxi += i*pos[i-1];
            }
            return maxi;
        }
        else if(pos.size()==0)
            return 0;
        else{
            sort(pos.begin(),pos.end());
            sort(neg.begin(),neg.end());
            stack<int> p;
            for(int i=pos.size()-1;i>=0;i--)
                p.push(pos[i]);
            for(int i=1;i<=pos.size();i++)
            {
                maxi += i*pos[i-1];
            }
            for(int i=neg.size()-1;i>=0;i--)
            {
                p.push(neg[i]);
                if(check(p,maxi))
                    continue;
                else
                    break;
            }
            return maxi;
        }   
    }
};

class Solution {
public:

    int solve(vector<int>& satisfaction,int index,int time)
    {
        if(index==satisfaction.size())
            return 0;
        int incl = (time+1)*satisfaction[index]+solve(satisfaction,index+1,time+1);
        int excl = solve(satisfaction,index+1,time);
        return max(incl,excl);
    }

    int solveMem(vector<int>& satisfaction,int index,int time,vector<vector<int>>& dp)
    {
        if(index==satisfaction.size())
            return 0;

        if(dp[index][time]!=-1)
            return dp[index][time];

        int incl = (time+1)*satisfaction[index]+solveMem(satisfaction,index+1,time+1,dp);
        int excl = solveMem(satisfaction,index+1,time,dp);
        dp[index][time] = max(incl,excl);
        return dp[index][time];
    }

    int solveTab(vector<int>& satisfaction)
    {
        int n= satisfaction.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int index=n-1;index>=0;index--)
        {
            for(int time=index;time>=0;time--)
            {   
                int incl = (time+1)*satisfaction[index]+dp[index+1][time+1];
                int excl = dp[index+1][time];
                dp[index][time] = max(incl,excl);
            }
        }
        return dp[0][0];
    }

    int solveOpt(vector<int>& satisfaction)
    {
        int n= satisfaction.size();
        vector<int> curr(n+1,0);
        vector<int> next(n+1,0);
        for(int index=n-1;index>=0;index--)
        {
            for(int time=index;time>=0;time--)
            {   
                int incl = (time+1)*satisfaction[index]+next[time+1];
                int excl = next[time];
                curr[time] = max(incl,excl);
            }
            next=curr;
        }
        return curr[0];
    }

    int WithoutDP(vector<int>& satisfaction)
    {
        int res = 0;
        sort(satisfaction.begin() , satisfaction.end() );
        int n = satisfaction.size();

        int i = 0;
        while( i<n ){
            int ans = 0 , t = 1;
            for(int j=i ; j<n ; j++){
                ans = ans + (satisfaction[j] * (t++));
                res = max( res , ans);
            }
            i++;
        }
        return res;
    }

    int maxSatisfaction(vector<int>& satisfaction) {
        // return WithoutDP(satisfaction);
        sort(satisfaction.begin(),satisfaction.end());
        // return solve(satisfaction,0,0);
        // int n= satisfaction.size();
        // vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        // return solveMem(satisfaction,0,0,dp);
        // return solveTab(satisfaction);
        return solveOpt(satisfaction);
    }
};