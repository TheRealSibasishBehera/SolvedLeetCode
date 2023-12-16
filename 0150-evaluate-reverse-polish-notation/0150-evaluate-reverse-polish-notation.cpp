#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> st;
        for (const string &token : tokens) {
            if (isOperator(token)) {
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();

                if (token == "+") {
                    st.push(y + x);
                } else if (token == "-") {
                    st.push(y - x);
                } else if (token == "*") {
                    st.push(y * x);
                } else if (token == "/") {
                    if (x != 0) {
                        st.push(y / x);
                    } else {
                        continue;
                    }
                }
            } else {
                st.push(stoi(token));
            }
        }
        return st.top(); // Return the final result
    }

private:
    bool isOperator(const string &token) {
        return (token == "+" || token == "-" || token == "*" || token == "/");
    }
};

