class Solution {
public:
int maxProfit(vector<int> &prices)
{
    // here is basic sliding window theory
    // we need to find the max diffrence between the elements
    //  7 1 5 3 6 4
    int l = 0;
    int r = 1;
    int n = prices.size();
    int ans = 0;
    while (r < n)
    {
        int val = prices[r] - prices[l];
        ans = max(ans, val);
        if (prices[l] > prices[r])
        {
            l = r;
        }
        r++;
    }

    return ans;
}
};