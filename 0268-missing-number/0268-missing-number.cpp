class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum=0;
        int actSum = (n*(n+1))/2;
        for(int x:nums){
            sum=sum+x;
        }
        cout << sum << endl;
        cout << actSum<<endl;
        return actSum-sum;
    }
};