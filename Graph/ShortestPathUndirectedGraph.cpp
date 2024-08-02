#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<int> adj[N];
        for(int i=0;i<M;i++)
        {
            int u=edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> ans(N,0);
        ans[src]=0;
        bool visited[N]={false};
        queue<int> q;
        visited[src]=true;
        q.push(src);
        while(!q.empty())
        {
            int front = q.front();
            q.pop();
            for(int x: adj[front])
            {
                if(visited[x]==false)
                {
                    ans[x]=ans[front]+1;
                    q.push(x);
                    visited[x]=true;
                }
            }
        }
        for(int i=0;i<N;i++)
        {
            if(i==src)
                continue;
            if(ans[i]==0)
                ans[i]=-1;
        }
        return ans;
    }
};