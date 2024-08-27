#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    bool solve(vector<int>& nums,int index)
    {
        if(index>=nums.size()-1)
            return true;
        
        if(nums[index]==0)
            return false;
        
        for(int i=1;i<=nums[index];i++)
        {
            if(solve(nums,index+i))
                return true;
        }
        return false;
    }

    bool solveMem(vector<int>& nums,int index,vector<int>& dp)
    {
        if(index>=nums.size()-1)
            return true;

        if(nums[index]==0)
            return false;
        
        if(dp[index]!=-1)
            return dp[index];
        
        for(int i=1;i<=nums[index];i++)
        {
            if(solveMem(nums,index+i,dp))
                return dp[index]=true;
        }
        return dp[index]=false;
    }

    bool solveTab(vector<int>& nums)
    {
        int goal = nums.size() - 1;

        for (int i = nums.size() - 2; i >= 0; i--) {
            if (i + nums[i] >= goal) {
                goal = i;
            }
        }

        return goal == 0; 
        // int reach = 0;
        // for(int i=0;i<=reach;i++){
        //     reach = max(reach,i+nums[i]);
        //     if(reach >= nums.size()-1) return true;
        // }
        // return false;
    }

    bool canJump(vector<int>& nums) {
        if(nums.size()==1)
            return true;
        // return solve(nums,0);
        // vector<int> dp(nums.size(),-1);
        // return solveMem(nums,0,dp);
        return solveTab(nums);
    }
};