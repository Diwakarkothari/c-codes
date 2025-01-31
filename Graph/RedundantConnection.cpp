#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    bool dfs(vector<int> adj[],vector<bool>& visited,int i,int parent)
    {
        visited[i]=true;
        for(int x : adj[i])
        {
            if(visited[x]==false)
            {
                if(dfs(adj,visited,x,i))
                    return true;
            }
            else if(visited[x]==true && x!=parent)
                return true;
        }
        return false;
    }

    bool isCycle(vector<int> adj[],int V)
    {
        vector<bool> visited(V,false);
        for(int i=0;i<V;i++)
        {
            if(visited[i]==false)
            {
                if(dfs(adj,visited,i,-1))
                    return true;
            }
        }
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int p,q;
        int V=edges.size();
        vector<int> adj[V];
        for(int j=0;j<V;j++)
        {
            vector<int> adj[V];
            for(int i=0;i<V;i++)
            {
                if(i==j)
                    continue;
                int u=edges[i][0]-1;
                int v=edges[i][1]-1;
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
            if(isCycle(adj,V))
                continue;
            else
                p=edges[j][0];
                q=edges[j][1];
        }
        vector<int> ans;
        ans.push_back(p);
        ans.push_back(q);
        return ans;
        
    }
};