#include<bits/stdc++.h>
using namespace std;

    //    BEATS 100% Original by Me

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n=arr.size();
        if(n<3)
            return 0;
        if(n==3 && arr[1]>arr[0] && arr[1]>arr[2])
            return 3;
        else if(n==3)
            return 0;
        else
        {
            int ans=0;
            for(int i=1;i<n-1;i++)
            {
                if(arr[i]>arr[i-1] && arr[i]>arr[i+1])
                {
                    int ind=i;
                    int cnt=1;
                    int j=ind-1;
                    while(j>=0)
                    {
                        if(arr[j]<arr[j+1])
                        {    
                            cnt++;
                            j--;
                        }
                        else
                            break;
                    }
                    j=ind+1;
                    while(j<arr.size())
                    {
                        if(arr[j]<arr[j-1])
                        {   
                            cnt++;
                            j++;
                        }
                        else
                            break;
                    }
                    ans=max(ans,cnt);
                }
            }
            return ans;
        }
    }
};