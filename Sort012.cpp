#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        // DUTCH NATIONAL FLAG PROBLEM  
        // low indiactes that all the below low are 0 , vice versa for high
        // mid is used to traverse the array
        int low = 0, mid = 0, high = nums.size()-1;
        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else{
                swap(nums[mid], nums[high]);
                high--;
            }
        }
        // MY CODE 

            // int i=0,j=nums.size()-1;
            // while(i<j)
            // {
            //     while(nums[i]!=2 && i<j)
            //         i++;
            //     while(nums[j]!=0 && i<j)
            //         j--;
            //     if(i<j)
            //         swap(nums[i++],nums[j--]);
            // }
            // i=0;
            // j=nums.size()-1;
            // while(i<j)
            // {
            //     while(nums[i]!=2 && i<j)
            //         i++;
            //     while(nums[j]!=1 && i<j)
            //         j--;
            //     if(i<j)
            //         swap(nums[i++],nums[j--]);
            // }
            // i=0;
            // j=nums.size()-1;
            // while(i<j)
            // {
            //     while(nums[i]!=1 && i<j)
            //         i++;
            //     while(nums[j]!=0 && i<j)
            //         j--;
            //     if(i<j)
            //         swap(nums[i++],nums[j--]);
            // }
    }
};