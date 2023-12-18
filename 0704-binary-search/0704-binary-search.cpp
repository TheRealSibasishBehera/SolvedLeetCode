class Solution {
public:
int search(vector<int> &nums, int target)
{
    auto start= lower_bound(nums.begin(),nums.end(),target);
    if(start==nums.end()) return -1;
    int index = start - nums.begin();
    // if(nums)
    if(nums[index]!=target) return -1;
    else return index;
}
};