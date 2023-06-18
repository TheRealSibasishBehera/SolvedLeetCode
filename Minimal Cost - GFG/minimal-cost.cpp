//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

int helper(vector<int> &height, int n, int k, vector<int> &dp)
{
    if (n == 0)
        return 0;
    // if (n < 0)
    //     return 1e8;

    if (dp[n] != -1)
        return dp[n];

    int mini = INT_MAX;
    for (int i = 1; i <= k; i++)
    {
        // cout<<"hello"<<endl;
        if (n - i >= 0){
            int jump=helper(height, n - i, k, dp) + abs(height[n] - height[n - i]);
                        mini = min(mini, jump);
                                // cout<<mini<<":"<<n-i<<":"<<jump<<endl;


        }
            

    }
    dp[n] = mini;
}
int minimizeCost(vector<int> &height, int n, int k)
{
    vector<int> dp(n, -1);

    return helper(height, n - 1, k, dp);
}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends