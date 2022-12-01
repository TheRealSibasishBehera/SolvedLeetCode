class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
 vector<int>  ans ; 
int n = nums.size();
 set<int> s;
int sum =0 ;
int actSum = (n*(n+1))/2;
    
 for (int x : nums) {
        s.insert(x);
    }
        
        
for (int x: s){
    sum =sum +x ;
}

    unordered_map<int ,int > a ;
     for (auto it :  nums)
     {
        a[it]++;
     }

     for (auto i : a)
     {
        if(i.second==2){
           ans.push_back(i.first);
        }
    }
        
        ans.push_back(actSum-sum);

        return ans;
    }
    
};