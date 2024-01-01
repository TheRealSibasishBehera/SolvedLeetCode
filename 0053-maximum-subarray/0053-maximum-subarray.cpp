class Solution {
public:
    int maxSubArray(vector<int> &nums)
    {
        // sub array means contiguous
        // basic is o n^3 -> i, j, k
        // or keep track of sum to dont need k -> o(n^2)

        // use greedy

        // int l = 0;
        int currsum = 0;
        int maxi = nums[0];
        for (int i = 0; i <=nums.size() - 1; i++)
        {
            if(currsum<0) currsum=0;
            currsum+=nums[i];
            maxi=max(maxi,currsum);
        }
        return maxi;
    }
};