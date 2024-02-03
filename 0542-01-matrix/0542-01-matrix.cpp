class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &grid)
    {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> visited(m, vector<int>(n, -1));

        // soln need nearest 0s for every 1s
        // shud use bfs
        queue<pair<int, int>> q;
        int distance = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {

                if (grid[i][j] == 0)
                {
                    // FILL THE QUE WITH ALL 1s INITIALLY
                    q.push({i, j});
                    visited[i][j] = 0;
                }
            }
        }
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        distance = 1;
        // do bfs
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
                    if (newX >= 0 && newX < m && newY >= 0 && newY < n && visited[newX][newY] == -1)
                    {
                        visited[newX][newY] = distance;
                        q.push({newX, newY});
                    }
                }
            }

            distance++;
        }

        return visited;
    }
};