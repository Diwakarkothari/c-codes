#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum =0;
        int ans=0;
        unordered_map<int,int> m;
        m[0]=1;
        for(int  num : nums)
        {
            sum+=num;
            int x = sum-k;
            if(m.find(x)!=m.end())
                ans+=m[x];
            
            m[sum]++;
        }
        return ans;
    }
};