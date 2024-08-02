#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:    

    // void dfs(vector<int> adj[],int i,bool *visited,stack<int>& s)
	// {
	//     visited[i]=true;
	//     for(int x: adj[i])
	//     {
	//         if(visited[x]==false)
	//             dfs(adj,x,visited,s);
	//     }
	//     s.push(i);
	// }

    vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here

        // vector<int> ans;
	    // stack<int> s;
	    // bool visited[V]={false};
	    // for(int i=0;i<V;i++)
	    // {
	    //     if(visited[i]==false)
	    //         dfs(adj,i,visited,s);
	    // }
	    // while(!s.empty())
	    // {
	    //     ans.push_back(s.top());
	    //     s.pop();
	    // }
	    // return ans;


	    vector<int> ans;
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
	    while(!q.empty())
	    {
	        int front = q.front();
	        q.pop();
	        ans.push_back(front);
	        for(int u: adj[front])
	        {
	            indegree[u]--;
	            if(indegree[u]==0)
	                q.push(u);
	        }
	    }
	    return ans;
	}
};