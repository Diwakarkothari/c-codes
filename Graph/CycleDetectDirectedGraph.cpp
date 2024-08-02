#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool DFS(vector<int> adj[],int i,bool *visited,bool *dfsvisited)
    {
        visited[i]=true;
        dfsvisited[i]=true;
        for(int x : adj[i])
        {
            if(visited[x]==false)
            {
                if(DFS(adj,x,visited,dfsvisited))
                    return true;
            }
            else if(dfsvisited[x]==true)
                return true;
        }
        dfsvisited[i]=false;
        return false;
    }


    // Using Topological sorting
    bool BFS(int V, vector<int> adj[]) {
        // code here
	    vector<int> indegree(V,0);
	    for(int i=0;i<V;i++)
	    {
	        for(int x : adj[i])
	        {
	            indegree[x]++;
	        }
	    }
	    queue<int> q;
	    for(int i=0;i<V;i++)
	    {
	        if(indegree[i]==0)
	            q.push(i);
	    }
	    int count=0;
	    while(!q.empty())
	    {
	        int front = q.front();
	        q.pop();
	        for(int u: adj[front])
	        {
	            indegree[u]--;
	            if(indegree[u]==0)
	                q.push(u);
	        }
	        count++;
	    }
	    return (count!=V);
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        bool visited[V]={false};
        bool dfsvisited[V]={false};
        for(int i=0;i<V;i++)
        {
            if(visited[i]==false)
            {
                if(DFS(adj,i,visited,dfsvisited))
                    return true;
            }
        }
        return false;
    }
};