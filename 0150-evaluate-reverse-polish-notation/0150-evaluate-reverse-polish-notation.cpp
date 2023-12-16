#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
  int evalRPN(vector<string>& tokens) {
        stack<int> rpn; 
        for(int i = 0; i < tokens.size(); i++){
            string segment = tokens[i]; 
            
            if(segment == "+"|| segment == "-" || segment == "*" || segment =="/"){
                int val1 = rpn.top();
                rpn.pop();
                int val2 = rpn.top();
                rpn.pop();
                int new_val = 0;
                if(segment == "+"){
                    new_val = val1 + val2;
                }
                else if(segment == "-"){
                    new_val = val2 - val1;
                }
                else if(segment == "*"){
                    new_val = val1 * val2;
                }
                else if(segment == "/"){
                    new_val = floor(val2/val1);
                }
                rpn.push(new_val);
                
            }
            else{
                int val = stoi(segment);
                rpn.push(val);
            }
        }
        return rpn.top();
        
    }

private:
    bool isOperator(const string &token) {
        return (token == "+" || token == "-" || token == "*" || token == "/");
    }
};

