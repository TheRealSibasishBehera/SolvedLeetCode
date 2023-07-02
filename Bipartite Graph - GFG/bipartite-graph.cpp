//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
bool isBipartite(int V, vector<int> adj[])
{

    // Code here
    int vis[V];
    for (int i = 0; i < V; i++)
    {
        vis[i] = -1;
    }
    // int indegree[V] = {0};
    // int col =0;

    for (int i = 0; i < V; i++)
    {
        if (vis[i] == -1)
        {
            if (!dfs(i,0,adj, vis))
                return false;
        }
    }

    return true;
}

bool dfs(int V,int col, vector<int> adj[], int vis[])
{
        vis[V]=col;
        for (auto it : adj[V])
        {
            // indegree[it] -= 1;
            if (vis[it] == -1)
            {
                if(!dfs(it,!col,adj,vis)) {return false;}
            }
            else if (vis[it] == col)
            {
                return false;
            }
        }
    

    return true;
}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends