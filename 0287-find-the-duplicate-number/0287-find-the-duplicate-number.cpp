class Solution {
public:
    int findDuplicate(vector<int>& nums) {
    unordered_map<int ,int > a ;
     for (auto it :  nums)
     {
        a[it]++;
     }

     for (auto i : a)
     {
        if(i.second>1){
            return i.first;
        }


     }
             return -1;
    }
};