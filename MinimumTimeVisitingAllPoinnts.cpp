#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans=0;
        int n=points.size();
        if(n==1)
            return ans;
        int x1=points[0][0];
        int y1=points[0][1];
        for(int i=1;i<n;i++)
        {
            ans += max(abs(points[i][0]-x1),abs(points[i][1]-y1));
            x1=points[i][0];
            y1=points[i][1];
        }
        return ans;
    }
};