//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
void topo(vector<int> adj[], int indegree[] ,vector<int> &ans, queue<int> q)
{

    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        ans.push_back(x);

        for (auto it: adj[x])
        {
            indegree[it]--;
            if(indegree[it]==0) q.push(it);
        }
        
    }
    
    return ;
}
bool isCyclic(int V, vector<int> adj[])
{
    // code here

    // USE bfs

    int vis[V] = {0};
    int indegree[V] = {0};
    vector<int> ans;
    // first we need to find the indegree
    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i]){
            indegree[it]+=1;
        }
    }

    queue<int> q;

    for (int i = 0; i < V; i++)
    {
        if(indegree[i]==0) q.push(i);
    }

    topo(adj,indegree,ans,q);
    
    // cout<<ans.size()<<endl;
    if (ans.size() == V)
    {
        return false;
    }
    return true;
    
    // for (int i = 0; i < V; i++)
    // {
    //     if(!vis[i]) topo(i,adj,vis,indegree,ans,q);
    // }
        
}
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends