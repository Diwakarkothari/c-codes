#include <bits/stdc++.h>
using namespace std;
vector<vector<string>> Anagrams(vector<string> &string_list)
{
    // code here

    // unordered_map error dega
    // The unordered_map requires a hash function for the key type, and vector<int> 
    // doesn't have a built-in hash function, leading to a compilation error.
    map<vector<int>, vector<string>> m;
    vector<vector<string>> ans;

    for (string str : string_list)
    {
        vector<int> temp(26, 0);
        for (int i = 0; i < str.length(); i++)
        {
            int index = str[i] - 'a';
            temp[index]++;
        }
        m[temp].push_back(str);
    }

    for (auto i : m)
        ans.push_back(i.second);

    sort(ans.begin(), ans.end());
    return ans;
}
