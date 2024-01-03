class Solution
{
public:
    bool isSubIsland = true;
    //primary is finding island in grid2
    bool dfs(vector<vector<int>> &grid1, vector<vector<int>> &grid2, int i, int j, vector<vector<bool>> &vis )
    {
        // grid2  has water 
        if (i < 0 || j < 0 || i >= grid1.size() || j >= grid1[0].size() || vis[i][j] || grid2[i][j] == 0)
            return isSubIsland;
        vis[i][j] = true;

        //grid 1 is not land -> it wont be a sub island
        if(grid2[i][j] != grid1[i][j]) isSubIsland = false;

        //traverse in all 4 directions
        dfs(grid1, grid2, i + 1, j, vis );
        dfs(grid1, grid2, i - 1, j, vis);
        dfs(grid1, grid2, i, j + 1, vis);
        dfs(grid1, grid2, i, j - 1, vis);

        return isSubIsland;
    }
    int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2)
    {
        // basic dfs
        int n = grid1.size(), m = grid1[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int ans = 0;
        for (int i = 0; i < grid1.size(); i++)
        {
            for(int j=0;j<grid1[0].size();j++)
            {
                isSubIsland=true;
                //grid 2 has land 
                if(!vis[i][j] && grid2[i][j] == 1)
                {
                    ans += dfs(grid1, grid2, i, j, vis);
                }
            }
        }
        

        return ans;
    }
};