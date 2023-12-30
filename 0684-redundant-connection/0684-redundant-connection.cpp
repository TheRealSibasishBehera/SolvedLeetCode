class Solution {
public:
vector<int> findRedundantConnection(vector<vector<int>> &edges)
{
    vector<int> rank(1001, -1);
    vector<int> parent(1001, -1); // Initialize with -1
    for (int i = 0; i < edges.size(); i++)
    {
        int a = edges[i][0];
        int b = edges[i][1];

        if (!union_nodes(a, b, rank, parent))
            return {a, b};
    }

    return {};
}

int find_par(int x, vector<int> &parent)
{
    if (parent[x] == -1)
        return x;
    else
        return find_par(parent[x], parent);
}

bool union_nodes(int a, int b, vector<int> &rank, vector<int> &parent)
{
    // Base case: if same parent, it will be a redundant connection
    int parA = find_par(a, parent);
    int parB = find_par(b, parent);
    if (parA == parB)
        return false;

    // Union by rank
    if (rank[parA] > rank[parB])
    {
        // Merge b to a
        parent[parB] = parA;
        rank[parA] += rank[parB];
    }
    else
    {
        parent[parA] = parB;
        rank[parB] += rank[parA];
    }

    return true;
}

};