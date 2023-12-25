// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
int firstBadVersion(int n)
{
    //kind of find first element
    // int n = arr.size();
    int start = 0;
    int end = n ;
    int ans = -1;
    while (start <= end)
    {
            int mid = start + (end - start) / 2;

        if (isBadVersion(mid))
        {
            // we want to be dec index that is dec the start that is mid-1

            ans = mid;
            end = mid - 1;
        }
        else 
        {
            start = mid + 1;
        }
    }
    return ans;
}
};