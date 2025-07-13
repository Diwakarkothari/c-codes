#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    int maxSubArray(vector<int>& nums) {
        // TLE
        // int n=nums.size();
        // if(n==1)
        //     return nums[0];
        // int ans=INT_MIN;
        // for(int i=0;i<n;i++)
        // {
        //     int sum=nums[i];
        //     ans=max(sum,ans);
        //     for(int j=i+1;j<n;j++)
        //     {
        //         sum+=nums[j];
        //         ans=max(ans,sum);
        //     }
        // }
        // return ans;
        int sum=0;
        int ans=nums[0];
        for(int i=0;i<nums.size();i++)
        {
            if(sum<0)
                sum=0;
            sum+=nums[i];
            ans=max(ans,sum);
        }
        return ans;
    }
};