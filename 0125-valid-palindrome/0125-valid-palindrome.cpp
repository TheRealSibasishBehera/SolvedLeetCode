class Solution {
public:
bool isPalindrome(string s)
{
    string ans="";
    for (auto ch : s)
    {
        if(ch>='a' &&  ch<='z'){
            ans+=ch;
        }
        if (ch >= 'A' && ch <= 'Z')
        {
            ans+=ch+('a'-'A');
        }
                if (ch >= '0' && ch <= '9')
        {
            ans+=ch;
        }
    }
    // cout<<ans<<endl;
    // if(ans.size()==0) return true;
    int i = 0;
    int j = ans.size() - 1;
    while(i<=j){
        if(ans[i]!=ans[j]){
            return false;
        }
        i++;
        j--;
    }

    return true;
    
}
};