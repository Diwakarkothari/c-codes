#include<bits/stdc++.h>
using namespace std;
bool dfs(vector<int> adj[],int i,vector<bool>& visited,int parent)
    {
        visited[i]=true;
        for(int x : adj[i])
        {
            if(visited[x]==false)
            {
                if(dfs(adj,x,visited,i))
                    return true;
            }
            else if(visited[x]==true && x!=parent)
                return true;
        }
        return false;
    }
    
    bool bfs(vector<int> adj[],int i,vector<bool>& visited,int V)
    {
        queue<int> q;
        vector<int> parent(V,-1);
        visited[i]=true;
        q.push(i);
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
                    parent[x]=front;
                }
                else if(visited[x]==true && x!=parent[front])
                    return true;
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool> visited(V,false);
        // for(int i=0;i<V;i++)
        // {
        //     if(visited[i]==false)
        //     {
        //         if(dfs(adj,i,visited,-1))
        //             return true;
        //     }
        // }
        
        
        for(int i=0;i<V;i++)
        {
            if(visited[i]==false)
            {
                if(bfs(adj,i,visited,V))
                    return true;
            }
        }
        
        return false;
    }