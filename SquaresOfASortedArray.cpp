#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> pos;
        vector<int> neg;
        int size=nums.size();
        for(int i=0;i<size;i++)
        {
            if(nums[i]<0)
                neg.push_back(nums[i]*nums[i]);
            else
                break;
        }
        int s=0,e=neg.size()-1;
        while(s<e)
        {
            swap(neg[s++],neg[e--]);
        }
        for(int i=0;i<size;i++)
        {
            if(nums[i]>=0)
                pos.push_back(nums[i]*nums[i]);
        }
        vector<int> ans;
        int i=0,j=0;
        while(i<pos.size() && j<neg.size())
        {
            if(pos[i]<=neg[j])
                ans.push_back(pos[i++]);
            else
                ans.push_back(neg[j++]);
        }
        while(i<pos.size())
            ans.push_back(pos[i++]);
        while(j<neg.size())
            ans.push_back(neg[j++]);
        return ans;
    }
};