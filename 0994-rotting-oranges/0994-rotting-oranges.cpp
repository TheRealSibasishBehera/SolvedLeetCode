class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {

        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int old_rotten = 0, new_rotten = 0;
        int fresh = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    fresh++;
                }
                else if (grid[i][j] == 2)
                {
                    // FILL THE QUE WITH ALL 2s INITIALLY
                    q.push({i, j});
                }
            }
        }

        int time = 0;
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!q.empty())
        {
            int s = q.size();

            for (int k = 0; k < s; k++)
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for (const auto &dir : directions)
                {
                    int newX = x + dir.first;
                    int newY = y + dir.second;
                    if (newX >= 0 && newX < m && newY >= 0 && newY < n && grid[newX][newY] == 1)
                    {
                        // visited[newX][newY] = 1;
                        grid[newX][newY] = 2;
                        q.push({newX, newY});
                        fresh--;
                    }
                }
            }

            if (!q.empty())
            {
                time++; // Increment time only if there are more oranges to rot
            }
        }
        // cout << new_rotten << " " << old_rotten << endl;
        if (fresh == 0)
        {
            return time;
        }
        return -1;
    }
};