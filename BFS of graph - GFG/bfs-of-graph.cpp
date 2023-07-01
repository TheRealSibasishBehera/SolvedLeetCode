//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
        void bfs(int node, vector<int> adj[],queue<int> &st,int vis[],vector<int> &ans) {
        // Code here
        st.push(node);

        while(!st.empty()){
            int x = st.front();
            st.pop();
                    ans.push_back(x);

        for(auto it:adj[x]){
            if(!vis[it]) {
                vis[it] = 1;
                st.push(node);
            }
        }
        }



    }
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        queue<int> st;
        vector<int> ans;
                int vis[V]={-1};

        
             st.push(0);
             vis[0]=1;

        while(!st.empty()){
            int x = st.front();
            st.pop();
                    ans.push_back(x);

        for(auto it:adj[x]){
            if(!vis[it]) {
                vis[it] = 1;
                st.push(it);
            }
        }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends