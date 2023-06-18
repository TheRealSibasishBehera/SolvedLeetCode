//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
int helper(int *arr, int n, vector<int> &dp)
{
       if (dp[n] != -1)
        return dp[n];
        
  
    if(n==0) return arr[n];
    if(n<0)  return 0;

 

    // take
    int take = arr[n] + helper(arr, n - 2,dp);
    // not take
    int not_take = helper(arr, n - 1,dp);

    return dp[n]=max(take, not_take);
}
int findMaxSum(int *arr, int n)
{
    // vector<int> dp(n, -1);

    // return helper(arr, n-1, dp);
        //tabulation
     vector<int> dp(n, -1);
    dp[0] = arr[0];

    for (int i = 1; i < n; i++)
    {
        int take = arr[i];
        // take
        if (i - 2 >= 0)
            take += + dp[i - 2];
        // not take
        int not_take = dp[i - 1];

         dp[i] = max(take, not_take);
    }
    return dp[n-1];
}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends