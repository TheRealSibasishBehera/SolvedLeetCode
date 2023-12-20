class Solution {
public:
bool check(vector<int> &nums,int m,int k,int mid){
    int bouq = 0;
    int flowers = 0;


    for(int i=0;i<nums.size();i++){
        if(nums[i]<=mid){
            flowers++;
            if(flowers==k){
                bouq++;
                flowers=0;
            }
        }
        else{
            flowers=0;
        }
    }
    return bouq>=m;
}
int minDays(vector<int> &nums, int m, int k)
{
    long long int val = static_cast<long long int>(m) * k; // Ensure the multiplication doesn't overflow
    if (nums.size() < val) return -1;
    int start = 0;
    long long int end = *max_element(nums.begin(), nums.end()); // Change the type to long long int
    while (start <= end) {
        long long int mid = start + (end - start) / 2;
        if (check(nums, m, k, mid)) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return static_cast<int>(end + 1);
}

};