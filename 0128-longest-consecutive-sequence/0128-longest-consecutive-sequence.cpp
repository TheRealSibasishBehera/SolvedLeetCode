class Solution {
public:
    //using a set takes O(n) but space is O(n)
    int longestConsecutive(vector<int> &nums)
    {
        //think of it in a number line
        // 100 4 200 1 3 2
        // number line is 1 2 3 4       100 200
        // we only search from the element which dont have any prev element
        //like 1 and 100

        // convert vector to set
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); i++)
        {
            s.insert(nums[i]);
        }

        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {

            //if prev element is not present
            //continue
            if(s.find(nums[i]-1) != s.end())
                continue;
            else{
                int curr= 0;
                while(s.find(nums[i]++) != s.end()){
                    curr++;
                
                }
                ans = max(ans,curr);
            }
        }

        return ans;
    }
};