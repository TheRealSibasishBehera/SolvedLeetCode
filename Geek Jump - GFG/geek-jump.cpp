//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int helper(vector<int>& height  , int n, vector<int>& dp)
    {
        //base case
        if(n==0) return 0;
        if(n<0) return 1e8;
        
        if(dp[n]!=-1) return dp[n];
        // int two=INT_MAX;
        //two cases
        int one = abs(height[n]-height[n-1])+helper(height, n-1,dp);
        int two = abs(height[n]-height[n-2]) +helper(height, n-2,dp);
        
        return dp[n]=min(one,two);
    }
    int minimumEnergy(vector<int>& height, int n) {
    vector<int> dp(n, -1);
    dp[0]=0;
    // dp[1]=abs(height[0] - height[1]);
    for (int i = 1; i < n; i++)
    {
              int two = INT_MAX;

        int one= dp[i-1]+abs(height[i] - height[i - 1]);
       if(i>1)  two= dp[i-2]+abs(height[i] - height[i - 2]);
        dp[i]= min(one,two);
    }
    
    return dp[n-1];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends