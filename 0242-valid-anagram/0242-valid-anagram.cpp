class Solution {
public:
bool isAnagram(string s, string t)
{
    
               if (s.size() != t.size())
        return false;
    //MAKE 2 SET AND CHECK IF EQUAL
    // OR MAKE 1 SET AND CHECK IF SIZE IS 0 IF s++ t--;

    unordered_map<char,int> mp;
    for (int i = 0; i < s.size(); i++)
    {
        mp[s[i]]++;
        mp[t[i]]--;
    }

    for(auto x:mp){
        if(x.second!=0) return false;
    }
    return true;    
}
};