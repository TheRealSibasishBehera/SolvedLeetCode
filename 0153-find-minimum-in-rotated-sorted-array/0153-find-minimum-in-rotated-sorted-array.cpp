class Solution {
public:
int findMin(vector<int> &nums){
    int start = 0;
    int end = nums.size() - 1;
    int ans = INT_MAX;

        // basically one part has to be sorted
        //2 part can be sorted once we enter sorted section 
        // so we do one thing , we keep min of sorted
        // and then we move to unsorted section
        // do the same there , divide into unsorted and sorted
        // and keep min of sorted

        while(start<=end){
            int mid = start + (end-start)/2;

            //full array is sorted
            //we can end now
            if(nums[start]<=nums[end]){
                ans = min(ans,nums[start]);
                break;
            }

            //left is sorted
            else if(nums[start]<=nums[mid]){
                ans= min(ans,nums[start]);
                start=mid+1;
            }

            //left is unsorted
            else if(nums[mid]<=nums[end]){
                ans=min(ans,nums[mid]);
                end=mid-1;
            }
        }

        return ans;
    }
};