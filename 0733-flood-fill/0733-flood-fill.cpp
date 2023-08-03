#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &grid, int sr, int sc, int color)
    {
        if(grid[sr][sc]==color) return grid;
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        int start=0;
        queue<pair<int, int>> q;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                // if (grid[i][j] != 0)
                    // count++;
                if (sr==i && sc==j)
                {
                    start=grid[i][j];
                    grid[i][j]=color;
                    q.push({i, j});
                }
            }
        }

        int delx[] = {-1, 0, 1, 0};
        int dely[] = {0, -1, 0, 1};
        int tmax = 0;
        while (!q.empty())
        {
            // printGrid(grid);

            int x = q.front().first;
            int y = q.front().second;
            // int t = q.front().second;
            // cout<<x<<","<<y<<endl;
            q.pop();

            for (int i = 0; i < 4; ++i)
            {
                int nx = x + delx[i];
                int ny = y + dely[i];

                if (nx >= 0 && ny >= 0 && nx < n && ny < m)
                {
                    if (grid[nx][ny] == start)
                    {
                        // tmax = max(tmax, t + 1);
                        q.push({nx, ny});
                        grid[nx][ny] = color;
                    }
                }
            }
        }

        return grid;
    }
};