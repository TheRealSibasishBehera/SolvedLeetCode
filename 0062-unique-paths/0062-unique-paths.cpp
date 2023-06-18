class Solution
{
public:
    int helper(int i, int j, vector<vector<int>> &dp)
    {

        if (dp[i][j] != -1)
            return dp[i][j];

         if(i<0 || j<0)
    return 0;
        // base case is out of bounds
        if (i == 0 && j == 0)
        {
            return 1;
        }
        int up = 0, left = 0;
        if (i - 1 >= 0)
            up = helper(i - 1, j, dp);
        if (j - 1 >= 0)
            left = helper(i, j - 1, dp);

        return dp[i][j] = up + left;
    }
    int uniquePaths(int m, int n)
    {
    vector<vector<int> > dp(m,vector<int>(n,-1));
 for(int i=0; i<m ;i++){
      for(int j=0; j<n; j++){
          
          //base condition
          if(i==0 && j==0){
              dp[i][j]=1;
              continue;
          }
          
          int up=0;
          int left = 0;
          
          if(i>0) 
            up = dp[i-1][j];
          if(j>0)
            left = dp[i][j-1];
            
          dp[i][j] = up+left;
      }
  }
  
  return dp[m-1][n-1];
    }
};
