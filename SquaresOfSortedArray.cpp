class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        if(nums[0]>=0)
        {
            for(int i=0;i<nums.size();i++)
                ans.push_back(nums[i]*nums[i]);
            return ans;
        }
        int n=nums.size();
        if(nums[n-1]<=0)
        {
            for(int i=n-1;i>=0;i--)
                ans.push_back(nums[i]*nums[i]);
            return ans;
        }
        vector<int> A;
        vector<int> B;
        int index=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>=0){
                index=i;
                break;
            }
        }
        for(int i=index-1;i>=0;i--)
            A.push_back(abs(nums[i]));
        for(int i=index;i<n;i++)
            B.push_back(nums[i]);
        int i=0,j=0;
        while(i<A.size() && j<B.size())
        {
            if(A[i]<=B[j])
            {
                ans.push_back(A[i]*A[i]);
                i++;
            }
            else
            {
                ans.push_back(B[j]*B[j]);
                j++;
            }
        }
        while(i<A.size())
        {
                ans.push_back(A[i]*A[i]);
                i++;
        }
        while(j<B.size())
        {
                ans.push_back(B[j]*B[j]);
                j++;
        }
        return ans;
    }
};