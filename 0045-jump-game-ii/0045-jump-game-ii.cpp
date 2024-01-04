class Solution
{
public:
    int jump(vector<int> &nums)
    {
        // basic thing is get as far as possible
        // so instead of checking for every index

        // we can check for every jump
        // and then check for the max index we can reach from that jump
        // and then we can jump to that index

        // its kind of like bfs

        int l = 0, r = 0;
        int result=0;
        //when when it will end r == n-1
        while (r < nums.size() - 1)
        {
            int fartherst=0;
            for(int i = l ; i <= r ; i++){
                fartherst = max(fartherst, i + nums[i]); //its cool how we are only checking max a index can go 
            }
            l = r + 1;
            r = fartherst;
            result++;
        }

        return result;
    }
};