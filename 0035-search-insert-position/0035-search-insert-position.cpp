class Solution {
public:
int searchInsert(vector<int> &arr, int target)
{

    //we know that lowerbound give iterator to the element or just greater
    //perfect
    int x = lower_bound(arr.begin(),arr.end(),target)-arr.begin();
    return x;
}
};