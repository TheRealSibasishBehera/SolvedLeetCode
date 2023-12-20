class Solution {
public:
int findMin(vector<int> &nums)
{
    int start = 0;
    int end = nums.size() - 1;
    int ans=INT_MAX;
    while (start<=end)
    {
        int mid = start + (end-start)/2;



        //when u know for sure
        //that the array is sorted
        //then u can directly return the start
        //as the min element
        if(nums[start]<=nums[end])
        {
            ans = min(ans,nums[start]);
            // return ans;
            break;
        }
        //FIRST HALD IS SORTED
        if(nums[start]<=nums[mid])
        {
            ans= min(ans,nums[start]);
            start=mid+1;
        }

        //SECOND HALF IS SORTED
        else if(nums[mid]<=nums[end])
        {
            ans=min(ans,nums[mid]);
            end=mid-1;
        }



    }

    return ans;
}
};