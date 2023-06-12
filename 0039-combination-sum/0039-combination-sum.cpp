class Solution {
public:
        vector<vector<int>> final;

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
           vector<int> temp;
    combinationSumHelper(candidates, 0, target, temp);
        return final;
    }
void combinationSumHelper(vector<int> &candidates, int n, int target, vector<int> &temp)
{
    // cout<<candidates.size()-1<<endl;
    if (n == candidates.size())
    {
        if (target == 0)
        {
            // cout<<"hello"<<endl;
            // for (int i = 0; i < temp.size(); i++)
            //     {cout << temp.at(i);}
            final.push_back(temp);
        }

        return;
    }
    // cout<<target<<endl;
    // every element has two option to be included ot nor

if (candidates[n]<=target)
{
    temp.push_back(candidates[n]);
    combinationSumHelper(candidates, n, target - candidates[n], temp);
    temp.pop_back();
}
    combinationSumHelper(candidates, n + 1, target, temp);
    return;
}
};