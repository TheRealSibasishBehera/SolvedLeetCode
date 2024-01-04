class Solution
{
public:
    bool helper(vector<int> &nums, int goal)
    {
        if (goal == 0)
            return true;
        for (int i = goal - 1; i >= 0; i--)
        {
            //if we can reach goal from i
            // for eg 2 3 2 , say 2 is the goal
            // now is 3 >= 2- (1)   , goal - i is the distance from i to goal
            // but 2 < 2- (0)  
            if (nums[i] >= goal - i)
                return helper(nums, i);

            //cool but what if we can have a ans that can come wrong , but a index before that come true
            //its impossible 
            //because u can obviously reach i if u can reach i+x
            // that mean if smoething fails , it would also have failed for i+x
        }
        return false;
    }
    bool canJump(vector<int> &nums)
    {
        int goal = nums.size() - 1;
        return helper(nums, goal);
    }
};