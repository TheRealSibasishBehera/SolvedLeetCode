class Solution {
private:
    //same cide 
    int find_parent(vector<int>& parent, int u) {
        if (parent[u] == u) 
            return u;
        return parent[u] = find_parent(parent, parent[u]);
    }

    //kind of same
    void union_by_rank(vector<int>& parent, vector<int>& rank, int u, int v) {
        if (rank[u] < rank[v])
            swap(u, v);

        int pu = find_parent(parent, u);
        int pv = find_parent(parent, v);

        rank[u] += rank[v];

        parent[pv] = pu;
    }
    
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n = edges.size();
        
        vector<int> parent(n+1);
        vector<int> rank(n+1, 1);
        
        
        //init parent with itself
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        
        //generic
        for (auto& edge: edges) {
            int u = edge[0];
            int v = edge[1];
            
            //if parent is same its the ans;
            if (find_parent(parent, u) == find_parent(parent, v)) {
                return vector<int>{u, v};
            } else {
                union_by_rank(parent, rank, u, v);
            }
        }
        return vector<int>();
    }
        
};