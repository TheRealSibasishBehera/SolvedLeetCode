class Solution
{
public:
    vector<vector<int>> final;

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        combinationSumHelper(candidates, 0, target, temp);
        return final;
    }

    void combinationSumHelper(vector<int> &candidates, int n, int target, vector<int> &temp)
    {
        // if (n == candidates.size())
        // {
            if (target == 0)
            {
                final.push_back(temp);
                return;
            }

        // }

        // COOL PART -> if 2 element are same , we cant make the same call

        for (int i = n; i <= candidates.size() - 1; i++)
        {

            // if its same as predecessor , leave

            if (i!=n && candidates[i] == candidates[i-1]){continue ;}
            
            if (candidates[i] > target){break ;}

                temp.push_back(candidates[i]);
                combinationSumHelper(candidates, i + 1, target - candidates[i], temp);
                temp.pop_back();
                // combinationSumHelper(candidates, n + 1, target, temp);
                
            
        }

        return;
    }
};