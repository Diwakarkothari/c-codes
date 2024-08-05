#include<bits/stdc++.h>
using namespace std;

//    ROTATION ALLOWED HAI 
//   WE CAN MAKE WIDTH THE HEIGHT HEIGHT THE LENGTH KAISE BHI NO PROBLEM

// different version of longest inctreasing subsequence
class Solution {
public:

    bool check(vector<int> a,vector<int> b)
    {
        if(a[0]>=b[0] && a[1]>=b[1] && a[2]>=b[2])
            return true;
        else
            return false;
    }

    int solveOpt(vector<vector<int>>& a)
    {
        int n = a.size();
        vector<int> c(n+1,0),next(n+1,0);
        for(int curr=n-1;curr>=0;curr--)
        {
            for(int pre=curr-1;pre>=-1;pre--)
            {
                int incl=0;
                if(pre==-1 || check(a[curr],a[pre]))
                    incl = a[curr][2] +next[curr+1];
                    
                int excl = next[pre+1];
                c[pre+1] = max(incl,excl);
            } 
            next=c;
        }
        return c[0];
    }

    int maxHeight(vector<vector<int>>& cuboids) {
        for(int i=0;i<cuboids.size();i++)
            sort(cuboids[i].begin(),cuboids[i].end());
        
        sort(cuboids.begin(),cuboids.end());
        return solveOpt(cuboids);
    }
};