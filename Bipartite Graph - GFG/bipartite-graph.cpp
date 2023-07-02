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
            if (!check(i, adj, vis))
                return false;
        }
    }

    return true;
}

bool check(int V, vector<int> adj[], int vis[])
{
    queue<int> q;
    q.push(V);
    int col = 1;
    vis[V] = col;
    // bfs(0, -1, col,adj, vis, q);
    // vis[node] = 1;

    while (!q.empty())
    {

        int x = q.front();
        q.pop();
        int parCOl = vis[x];
        // ans.push_back(x);
        for (auto it : adj[x])
        {
            // indegree[it] -= 1;
            if (vis[it] == -1)
            {
                q.push(it);
                vis[it] = !parCOl;
            }
            else if (vis[it] == parCOl)
            {
                return false;
            }
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