class Solution {
public:
bool isValid(string s)
{
    
    if(s.length()%2!=0) return false;
    stack<char> st;
    for(char ch :s){
        if(ch=='(' || ch=='[' ||ch=='{'){
            st.push(ch);
        }
        else if (ch == '}'){

            if(!st.empty() && st.top() == '{') st.pop();
            else return false;
        }
        else if (!st.empty() && ch == ']')
        {

            if (st.top() == '[')
                st.pop();
            else
                return false;
        }
        else if (!st.empty() && ch == ')')
        {

            if (st.top() == '(')
                st.pop();
            else
                return false;
        }
        
        else{
            st.push(ch);
        }
    }

        if (st.empty()) return true;
        return false;
    }
};