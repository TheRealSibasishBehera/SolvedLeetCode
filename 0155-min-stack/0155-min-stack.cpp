#include <vector>

class MinStack {
public:
    std::vector<int> st;
    std::vector<int> minst;

    MinStack() {
    }

    void push(int val) {
        st.push_back(val);

        if (minst.empty() || val <= minst.back()) {
            minst.push_back(val);
        }
    }

    void pop() {
            if (st.back() == minst.back()) {
                minst.pop_back();
            }
            st.pop_back();
    }

    int top() {
            return st.back();
    }

    int getMin() {
        return minst.back();
    }
    
    
    // thing its working is bcuz its a stack 
    // if we are having a x , y  , z with  x<y<z , only x is on the min stack
    // u might be thinking what if we pop , thing is if we pop it will be the last
    // ifx>y>z min st would be x y z 
    // we have all ele
};
