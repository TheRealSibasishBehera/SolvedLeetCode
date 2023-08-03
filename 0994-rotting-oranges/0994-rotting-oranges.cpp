class Solution {
	public:
	    int orangesRotting(vector<vector<int>>& grid) {
	        int n = grid.size();
	        int m = grid[0].size();
	        int count=0;
	        queue<pair<pair<int,int>,int>> q;
	        for (int i = 0; i < n; ++i)
	        {
	        	for (int j = 0; j < m; ++j)
	        	{
	        		if(grid[i][j]!=0) count++;
	        		if(grid[i][j]==2) q.push({{i,j},0});
	        	}
	        }

	        int delx[]={-1,0,1,0};
	        int dely[]={0,-1,0,1};
	        int tmax=0;
	        while(!q.empty()){
                
	        	int x = q.front().first.first;
	        	int y = q.front().first.second;
	        	int t = q.front().second;
                
                q.pop();

	        	for (int i = 0; i < 4; ++i)
	        	{
	        		int nx=x+delx[i];
	        		int ny=y+dely[i];

	        		if (nx>=0 && ny>=0 && nx<n && ny<m )
	        		{
	        			if ( grid[nx][ny]==1)
	        			{
	        				tmax=max(tmax,t+1);
	        				q.push({{nx,ny},t+1});
	        				grid[nx][ny]=2;
	        			}
	        		}
	        	}

	        }

	        int g_count=0;
	        // int max_time=0;
for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
        if (grid[i][j] == 2) g_count++;
        // if(grid[i][j]==0) q.push({i,j},0);
    }
}


if (count == g_count) return tmax;
	        return -1;
	    }
	};