class Solution {
public:
int helper(int x)
{
    long sum =0, dig = 0;
    int n = x;
    while (n)
    {
        // cout << n << endl;
        dig = n % 10;
        sum = sum * 10 + dig;
        n = n / 10;
    }
    if(sum>INT_MAX || sum<INT_MIN) return 0;
    return int(sum);
}
int reverse(int x)
{
    return helper(x);
}
};