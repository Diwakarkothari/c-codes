#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    int solve(vector<int>& nums1,vector<int>& nums2,int index,bool swapped)
    {
        if(index>=nums1.size())
            return 0;
        
        int ans=INT_MAX;
        int pre1=nums1[index-1];
        int pre2=nums2[index-1];

        if(swapped)
            swap(pre1,pre2);
        
        // no swap
        if(nums1[index]>pre1 && nums2[index]>pre2)
            ans=solve(nums1,nums2,index+1,false);

        if(nums1[index]>pre2 && nums2[index]>pre1)
            ans=min(ans,1+solve(nums1,nums2,index+1,1));
        
        return ans;
    }

    int solveMem(vector<int>& nums1,vector<int>& nums2,int index,bool swapped,vector<vector<int>>& dp)
    {
        if(index>=nums1.size())
            return 0;
        
        if(dp[index][swapped]!=-1)
            return dp[index][swapped];

        int ans=INT_MAX;
        int pre1=nums1[index-1];
        int pre2=nums2[index-1];

        if(swapped)
            swap(pre1,pre2);
        
        // no swap
        if(nums1[index]>pre1 && nums2[index]>pre2)
            ans=solveMem(nums1,nums2,index+1,false,dp);

        if(nums1[index]>pre2 && nums2[index]>pre1)
            ans=min(ans,1+solveMem(nums1,nums2,index+1,1,dp));
        
        return dp[index][swapped] = ans;
    }

    int solveTab(vector<int>& nums1,vector<int>& nums2)
    {
        vector<vector<int>> dp(nums1.size()+1,vector<int>(2,0));
        for(int index=nums1.size()-1;index>=1;index--)
        {
            for(int swapped=1;swapped>=0;swapped--)
            {
                int ans=INT_MAX;
                int pre1=nums1[index-1];
                int pre2=nums2[index-1];

                if(swapped)
                    swap(pre1,pre2);
                
                // no swap
                if(nums1[index]>pre1 && nums2[index]>pre2)
                    ans=dp[index+1][0];

                if(nums1[index]>pre2 && nums2[index]>pre1)
                    ans=min(ans,1+dp[index+1][1]);
                
                dp[index][swapped] = ans;
            }
        }
        return dp[1][0];
    }

    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(),-1);
        return solve(nums1,nums2,1,false);
        // vector<vector<int>> dp(nums1.size(),vector<int>(2,-1));
        // return solveMem(nums1,nums2,1,false,dp);
        // return solveTab(nums1,nums2);
    }
};