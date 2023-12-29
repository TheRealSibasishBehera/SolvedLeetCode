class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> parent(1001, -1);
        vector<int> rank(1001, 0);

        for (int i = 0; i < edges.size(); i++) {
            int x = edges[i][0];
            int y = edges[i][1];

            int parentX = findParent(x, parent);
            int parentY = findParent(y, parent);

            if (parentX == parentY) {
                return edges[i];
            }

            // Union by rank
            if (rank[parentX] > rank[parentY]) {
                parent[parentY] = parentX;
            } else if (rank[parentX] < rank[parentY]) {
                parent[parentX] = parentY;
            } else {
                parent[parentY] = parentX;
                rank[parentX]++;
            }
        }

        return {};
    }

private:
    int findParent(int node, vector<int>& parent) {
        if (parent[node] == -1) {
            return node;
        }
        return findParent(parent[node], parent);
    }
};
