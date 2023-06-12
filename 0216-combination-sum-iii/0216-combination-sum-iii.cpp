class Solution {
public:
vector<vector<int>> final;
vector<vector<int>> combinationSum3(int k, int n)
{
    vector<int> temp;
    helper(k,n,1,temp);
    return final;
}
void helper(int k, int n, int i, vector<int> temp)
{
    if (i > 10)
    {
        return;
    }
    if (k == 0 && n == 0)
    {
        final.push_back(temp);
        return;
    }


    // cout<<"p:"<<i<<endl;
    helper(k, n, i + 1, temp);
    
    temp.push_back(i);
    helper(k - 1, n - i, i + 1, temp);
    
}
};