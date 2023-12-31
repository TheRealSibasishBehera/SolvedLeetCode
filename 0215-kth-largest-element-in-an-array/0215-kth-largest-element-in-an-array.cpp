class Solution {
public:
int findKthLargest(vector<int> &nums, int k)
{
    // sort(nums.begin(), nums.end());
    // return (nums[nums.size() - k]);

    priority_queue<int, vector<int>, greater<>> pq;
    for (auto i : nums)
        pq.push(i);
    while (pq.size() > k)
        pq.pop();
    return pq.top();
}

};