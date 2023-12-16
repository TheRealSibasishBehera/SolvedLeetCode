class Solution {
public:
bool isAnagram(string s, string t)
{
    //MAKE 2 SET AND CHECK IF EQUAL
    // OR MAKE 1 SET AND CHECK IF SIZE IS 0 IF s++ t--;
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    if(s==t) return true;
    return false;
}
};