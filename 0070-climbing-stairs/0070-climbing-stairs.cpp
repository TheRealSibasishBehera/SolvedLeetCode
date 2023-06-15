class Solution {
public:
    int climbStairs(int n) {
        if(n==1){return 1;}
        if(n==0){return 1;}
    int prev = 1;
    int next = 1;
    int val;
    for (int i = 2; i <= n; i++)
    {
        val = prev + next;
        prev = next;
        next = val;
    }
    return val;}
    
};