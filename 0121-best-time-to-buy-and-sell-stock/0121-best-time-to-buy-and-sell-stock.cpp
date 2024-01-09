class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int pivot = prices[0] ;
        int maxi = INT_MIN;
        for(int i =0 ; i< prices.size();i++){
            maxi= max(maxi , prices[i] - pivot);
            if(prices[i]<pivot) pivot = prices[i];
        }
        
        
        return maxi;
    }
};