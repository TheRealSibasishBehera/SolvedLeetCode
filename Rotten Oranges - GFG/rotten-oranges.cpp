//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
int orangesRotting(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    queue<pair<pair<int, int>, int>> q;
    vector<vector<int>> vis(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 2)
            {
                q.push({{i, j}, 0});
                vis[i][j] = 2;
            }
        }
    }

    int maxT = 0;
    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};

    while (!q.empty())
    {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int time = q.front().second;

        maxT = max(maxT, time);
        q.pop();

        for (int p = 0; p < 4; p++)
        {
            int nrow = r + drow[p];
            int ncol = c + dcol[p];

            if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1)
            {
                vis[nrow][ncol] = 2;
                q.push({{nrow, ncol}, time + 1});
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j] != 2 && grid[i][j] == 1)
                return -1;
        }
    }

    return maxT;
}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends