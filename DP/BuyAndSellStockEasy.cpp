#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
// one time buy and sell
    int maxProfit(vector<int>& prices) {
        int minPrice=INT_MAX;
        int ans=0;
        for(int i=0;i<prices.size();i++)
        {
            minPrice=min(minPrice,prices[i]);
            ans=max(ans,prices[i]-minPrice);
        }
        return ans;
    }
};