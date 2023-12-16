class MinStack {
    std::vector<int> st;
    std::vector<int> minStack;

public:
    MinStack() {}

    void push(int val) {
        st.push_back(val);

        if (minStack.empty() || val <= minStack.back()) {
            minStack.push_back(val);
        }
    }

    void pop() {
        if (!st.empty()) {
            if (st.back() == minStack.back()) {
                minStack.pop_back();
            }
            st.pop_back();
        }
    }

    int top() {
        if (!st.empty()) {
            return st.back();
        }
        return -1;  // Handle the case when the stack is empty
    }

    int getMin() {
        if (!minStack.empty()) {
            return minStack.back();
        }
        return -1;  // Handle the case when the stack is empty
    }
};
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */