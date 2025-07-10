#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0,sum=0;
        int n=nums.size();
        int res=INT_MAX;
        for(int r=0;r<n;r++)
        {
            sum+=nums[r];
            while(sum>=target)
            {
                res=min(res,r-l+1);
                sum-=nums[l];
                l++;
            }
        }
        if(res==INT_MAX)
            return 0;
        else
            return res;
    }
};