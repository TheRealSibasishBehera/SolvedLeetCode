class Solution {
public:
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    //try to max diffrence 
    int min_price = INT_MAX;
    int ans=0;
    for (int i = 0; i < n; i++)
    {
        int diff= prices[i]-min_price;
        ans=max(ans,diff);
        if(diff<0) {
            min_price=prices[i];
        }
    }

    return ans;
    
}
};