class Solution {
public:
        int fib(int n) {

    int prev = 0, next=1;
    if (n==0) return prev;
    if (n==1) return next;
    int ans=0;
    
    for (int i = 2; i <= n; i++)
    {
        ans = prev +next;
        prev=next;
        next= ans;
    }
    return ans;
            }
};