#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> arr(101,0);
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            arr[nums[i]]++;
        }
        int sum=arr[0];
        vector<int> temp(101,0);
        for(int i=1;i<101;i++)
        {
            temp[i]=sum;
            sum+=arr[i];
        }
        for(int i=0;i<n;i++)
        {
            nums[i]=temp[nums[i]];
        }
        return nums;
    }
};