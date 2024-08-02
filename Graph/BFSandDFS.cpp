#include<bits/stdc++.h>
using namespace std;


void dfs(vector<vector<int>>& adj,int i,vector<bool>& visited,vector<int>& ans)
{
    visited[i]=true;
    ans.push_back(i);
    for(int x : adj[i])
    {
        if(visited[x]==false)
            dfs(adj,x,visited,ans);
    }
}

vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    // Write your code here.
    vector<int> ans;
    bool visited[n]={false};

    // BFS

    queue<int> q;
    q.push(0);
    visited[0]=true;
    ans.push_back(0);
    while(!q.empty())
    {
        int front = q.front();
        q.pop();
        for(int x : adj[front])
        {
            if(visited[x]==false)
            {
                q.push(x);
                visited[x]=true;
                ans.push_back(x);
            }
        }
    }


    // DFS

    // for(int i=0;i<n;i++)
    // {
    //     if(visited[i]==false)
    //         dfs(adj,i,visited,ans);
    // }
    return ans;
}