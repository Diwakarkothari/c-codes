#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:

    int rec(vector<int>& cost,int i,int ans)
    {
        if(i>=cost.size())
            return ans;
        
        return min(rec(cost,i+1,ans+cost[i]),rec(cost,i+2,ans+cost[i]));
    }

    int mem(vector<int>& cost,int i,vector<int>& arr)
    {
        if(i>=cost.size())
            return 0;
        
        if(arr[i]!=-1)
            return arr[i];

        arr[i] = min(mem(cost,i+1,arr)+cost[i],mem(cost,i+2,arr)+cost[i]);
        return arr[i];
    }

    int tab(vector<int>& cost)
    {
        vector<int> arr(cost.size()+1);
        arr[0]=cost[0];
        arr[1]=cost[1];

        for(int i=2;i<cost.size();i++)
        {
            arr[i]= cost[i] + min(arr[i-1],arr[i-2]);
        }
        int n=cost.size();
        return min(arr[n-1],arr[n-2]);
    }

    int spaceOptimization(vector<int>& cost)
    {
        int first=cost[0];
        int second=cost[1];

        for(int i=2;i<cost.size();i++)
        {
            int curr = cost[i] + min(first,second);
            first=second;
            second=curr;
        }
        return min(first,second);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        // vector<int> arr(cost.size()+1,-1);
        // return min(mem(cost,0,arr),mem(cost,1,arr));
        // return tab(cost);
        return spaceOptimization(cost);
    }
};