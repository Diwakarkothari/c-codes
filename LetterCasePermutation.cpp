#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    void solve(string s,vector<string>& ans,int i)
    {
        if (i == s.length()) 
        {
            ans.push_back(s);
            return;
        }

        if (isdigit(s[i])) 
        {
            solve(s, ans, i + 1);  
        } 
        else 
        {
            solve(s, ans, i + 1);
            s[i] = islower(s[i]) ? toupper(s[i]) : tolower(s[i]);
            solve(s, ans, i + 1);
        }
    }

    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        solve(s,ans,0);
        return ans;
    }
};