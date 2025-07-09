#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col = matrix[0].size();
        int startrow=0,endrow=row-1;
        int startcol=0,endcol=col-1;
        vector<int> ans;
        while(startrow<=endrow && endcol>=startcol)
        {
            for(int i=startcol;i<=endcol;i++)
                ans.push_back(matrix[startrow][i]);
            startrow++;
            for(int i=startrow;i<=endrow;i++)
                ans.push_back(matrix[i][endcol]);
            endcol--;
            if(startrow<=endrow)
            {
                for(int i=endcol;i>=startcol;i--)
                    ans.push_back(matrix[endrow][i]);
                endrow--;
            }
            if(startcol<=endcol)
            {
                for(int i=endrow;i>=startrow;i--)
                    ans.push_back(matrix[i][startcol]);
                startcol++;
            }
        }
        return ans;
    }
};