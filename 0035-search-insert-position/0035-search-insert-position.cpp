class Solution {
public:
int searchInsert(vector<int> &arr, int x)
{

    // we know that lowerbound give iterator to the element or just greater
    // perfect
    int n = arr.size();

    // we know that lowerbound give iterator to the element or just greater
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] >= x)
        {
            ans = mid;

            //KEY
            // look for smaller index on the left
            high = mid - 1;
        }
        else
        {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}
};