#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // sort taaki duplicate hata sake
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n= nums.size();

        for(int i=0;i<n;i++)
        {
            // ek ko fix kar diya hai aur duplicate nhi chahiye isliye
            // aage bad jayenge agar same element milega to
            if(i>0 && nums[i]==nums[i-1])
                continue;
            
            // two pointers approach
            int j=i+1;
            int k=n-1;
            while(j<k)
            {
                // if total is more we move back k else j
                int total=nums[i]+nums[j]+nums[k];
                if(total>0)
                    k-=1;
                else if(total<0)
                    j+=1;
                else
                {
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j+=1;
                    // pushing ans and moving away from duplicates
                    while(nums[j]==nums[j-1] && j<k)
                        j+=1;
                }
            }
        }
        return ans;
    }
};