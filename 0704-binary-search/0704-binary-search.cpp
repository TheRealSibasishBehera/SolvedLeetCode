class Solution {
public:
int search(vector<int> &nums, int target)
{
    int l = 0;
    int r = nums.size() - 1;
    int middle;
    //
    while(l<=r){
        middle=l+(r-l)/2;
        if(nums[middle]==target) return middle;
        else if(nums[middle]>target) r=middle-1;
        else l=middle+1;
    }

    return -1;
}
};