#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    static bool fun(const vector<int>& a,const vector<int>& b)
    {
        if(a[0]==b[0])
            return a[1]>b[1];
        else
            return a[0]<b[0];
    }

    int lis(vector<int>& a)
    {
        int n = a.size();
        vector<int> ans;
        ans.push_back(a[0]);
        // time complexity = O(NlogN)
        for(int i=1;i<n;i++)
        {
            if(a[i] > ans.back())
                ans.push_back(a[i]);
            else
            {
                // Binary search lagata hai to O(logN)
                int index = lower_bound(ans.begin(),ans.end(),
                        a[i])-ans.begin();
                ans[index]=a[i];
            }
        }
        return ans.size();
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if(envelopes.size()==0)
            return 0;
        sort(envelopes.begin(),envelopes.end(),fun);

        int ans=1;
        int out1=envelopes[0][0],out2=envelopes[0][1];

        // NOT WORKING BECAUSE OF THE SECOND INDEX CAN BE DYNAMIC IN  NATURE
        // NOT INCLUDING 1 CAN AFFECT THE ANSWER

        // for(int i=1;i<envelopes.size();i++)
        // {
        //     if(envelopes[i][0] > out1 && envelopes[i][1] > out2)
        //     {
        //         out1=envelopes[i][0];
        //         out2=envelopes[i][1];
        //         ans++;
        //     }
        // }
        // return ans;

        vector<int> a;
        for(int i=0;i<envelopes.size();i++)
        {
            a.push_back(envelopes[i][1]);
        }
        return lis(a);
    }
};