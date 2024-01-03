class Solution
{
public:
    bool isAlienSorted(vector<string> &words, string order)
    {

        int count = 0;
        for (int i = 0; i < words.size() - 1; i++)
        {
            int j = 0;
            int flag=0;
            while (j < words[i].size() && j < words[i + 1].size())
            {
                if (order.find(words[i][j]) > order.find(words[i + 1][j])) return false;
                if (order.find(words[i][j]) == order.find(words[i + 1][j]))
                    j++;
                else {flag=1;break;}
            }
            
            if(!flag && words[i].size() > words[i+1].size()) return false;
        }
        return true;
    }
};