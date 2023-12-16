class Solution {
public:
bool containsDuplicate(vector<int> &nums)
{
    unordered_map<int,int> mp;
    for(int i =0;i<nums.size();i++){
        int x =mp.count(nums[i]);
        if(x>=1) return true;
        else mp[nums[i]]=1;
    }
    return false;
}
};