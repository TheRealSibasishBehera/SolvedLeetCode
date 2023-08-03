#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> distance(n, vector<int>(m, -1)); // Initialize with -1

        // Initialize the queue with 0 cells and set distance to 0
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                    distance[i][j] = 0;
                }
            }
        }

        int delx[] = {-1, 0, 1, 0};
        int dely[] = {0, -1, 0, 1};
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int i = 0; i < 4; ++i) {
                int nx = x + delx[i];
                int ny = y + dely[i];

                if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                    if (distance[nx][ny] == -1) { // Check if not visited
                        q.push({nx, ny});
                        distance[nx][ny] = distance[x][y] + 1;
                    }
                }
            }
        }

        return distance;
    }
};
