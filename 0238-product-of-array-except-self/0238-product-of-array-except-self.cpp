class Solution {
public:
vector<int> productExceptSelf(vector<int> &nums)
{
    int n= nums.size();
    vector<int> prefix(n);
    prefix[0]=1;
    for(int i =1 ;i<n;i++){
        prefix[i] = prefix[i-1]*nums[i-1];
    }
    
    
    int suffix = 1;
    vector<int> ans(n);
    for(int i = n-1;i>=0;i--){
        ans[i]=suffix*prefix[i];
        suffix=suffix*nums[i];
    }
    
    return ans;
    
    
}
};