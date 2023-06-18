//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
long long int solve(vector<int>& arr){
    int n = arr.size();
    long long int prev = arr[0];
    long long int prev2 =0;
    
    for(int i=1; i<n; i++){
        long long int pick = arr[i];
        if(i>1)
            pick += prev2;
        int long long nonPick = 0 + prev;
        
        long long int cur_i = max(pick, nonPick);
        prev2 = prev;
        prev= cur_i;
        
    }
    return prev;
} //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
//   int n = arr.size();

    vector<int> dp(n, -1);
    dp[0] = arr[0];

    for (int i = 1; i < n; i++)
    {
        int take = arr[i]; // IMP STEP PPPPPPPPPPPPPPPPP
        // take
        if (i - 2 >= 0)
            take += +dp[i - 2];
        // not take
        int not_take = dp[i - 1];

        dp[i] = max(take, not_take);
    }
    return dp[n - 1];
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends