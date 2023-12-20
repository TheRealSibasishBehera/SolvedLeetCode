class Solution {
public:
int search(vector<int> &nums, int target)
{
    int l = 0;
    int r = nums.size() - 1;
    int middle;
    while (l <= r)
    {
        middle = l + (r - l) / 2;
        if (nums[middle] == target)
            return middle;

        // core thing is to reject a half of the array
        //  case1: //left half is sorted
        if (nums[l] <= nums[middle])
        {
            if (nums[l]<=target && nums[middle] >= target)
            {
                r = middle - 1;
            }
            else
            {
                l = middle + 1;
            }
        }
        // case2: //right half is sorted
        else if (nums[middle] <= nums[r])
        {
            if (nums[r] >= target && nums[middle] <= target)
            {
                l = middle + 1;
            }
            else
            {
                r = middle - 1;
            }
        }
    }

    return -1;
}

};