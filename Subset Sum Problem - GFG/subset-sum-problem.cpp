//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
            int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));

    return helper(arr, sum, n - 1, dp);
    }
    
bool helper(vector<int> &arr, int sum, int index, vector<vector<int>> &dp)
{
    // basecase
    if (sum == 0)
        return true;
    if (index == 0)
    {
        if (sum == arr[0])
        {
            return true;
        }
        return false;
    }

    if (dp[index][sum] != -1)
        return dp[index][sum];
    // take
    bool take = false;
    if (arr[index] <= sum)
        take = helper(arr, sum - arr[index], index - 1, dp);
    // not take
    bool notTake = false;
    notTake = helper(arr, sum, index - 1, dp);
    return dp[index][sum] = take || notTake;
}
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends