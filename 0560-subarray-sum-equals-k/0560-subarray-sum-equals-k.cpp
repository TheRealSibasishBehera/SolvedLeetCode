class Solution {
public:
int subarraySum(vector<int> &nums, int k)
{
    
    //lets optimize this
    // we can use prefix sum
    // sum[i] = sum[i-1] + nums[i]
    // sum[i] - sum[j] = k
    // sum[j] = sum[i] - k
    // we can use a map to store the sum and its frequency
    // if we find sum[i] - k in the map then we can add its frequency to the count
    // we can also store the sum and its frequency in the map before we start the loop
    // so that we can handle the case when sum[i] == k
    int n = nums.size();
    int count = 0;
    int sum = 0;
    unordered_map<int, int> mp;
    mp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        //keep adding the sum
        sum += nums[i];
        // check if sum - k is in the map
        if (mp.find(sum - k) != mp.end())
        {
            // if it is then add its frequency to the count
            count += mp[sum - k];
        }
        // add the sum to the map
        mp[sum]++;
    }

    return count;
}
};