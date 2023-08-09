class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));

        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, -1, 0, 1};

        while (!pq.empty()) {
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            int dis = pq.top().first;

            pq.pop();

            for (int i = 0; i < 4; i++) {
                int nx = x + delrow[i];
                int ny = y + delcol[i];

                if (nx >= 0 && nx < rows && ny >= 0 && ny < cols) {
                    int new_effort = max(dis, abs(heights[nx][ny] - heights[x][y]));

                    if (dist[nx][ny] > new_effort) {
                        dist[nx][ny] = new_effort;
                        pq.push({new_effort, {nx, ny}});
                    }
                }
            }
        }

        return dist[rows - 1][cols - 1]; // Return the minimum effort at the destination cell
    }
};
