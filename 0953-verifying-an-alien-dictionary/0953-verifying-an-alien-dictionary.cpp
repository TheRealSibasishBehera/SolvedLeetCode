class Solution
{
public:
    bool isAlienSorted(vector<string> &words, string order)
    {

        int count = 0;
        for (int i = 0; i < words.size() - 1; i++)
        {
            int j = 0;
            int flag = 0;
            for(int j = 0; j < words[i].size(); j++){
                if(j==words[i+1].size()) return false;
                
                //find the first mismatch
                if(words[i][j]!=words[i+1][j]){
                    if(order.find(words[i][j])>order.find(words[i+1][j])) return false;
                    else break;
                }
            }
        }
        return true;
    }
};