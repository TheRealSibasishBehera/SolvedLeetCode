class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return -1; // Check if the start or end cell is blocked
        }
        
        else if (grid[0][0] == 0 && grid.size()==1 && grid[0].size()==1 ) {
            return 1; // Check if the start or end cell is blocked
        }
        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX)); // Corrected the size
        
        dist[0][0] = 1; // Changed the distance for the starting cell
        q.push({1, {0, 0}});
        
        int delrow[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int delcol[] = {-1, 0, 1, -1, 1, -1, 0, 1}; // Added all 8 directions
        
        while (!q.empty()) {
            int x = q.front().second.first;
            int y = q.front().second.second;
            int dis = q.front().first;
            
            q.pop();
            
            for (int i = 0; i < 8; i++) { // Changed the loop to consider 8 directions
                int nx = x + delrow[i];
                int ny = y + delcol[i];
                
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 0) { // Check for validity
                    if (dist[nx][ny] > dis + 1) {
                        dist[nx][ny] = dis + 1;
                        if (nx == n - 1 && ny == n - 1) {
                            return dist[nx][ny];
                        }
                        q.push({dis + 1, {nx, ny}});
                    }
                }
            }
        }

        return -1;
    }
};
