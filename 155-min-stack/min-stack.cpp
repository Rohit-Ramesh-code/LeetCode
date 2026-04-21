#include <stack>
#include <algorithm>

class MinStack {
private:
    std::stack<std::pair<int, int>> st;

public:
    MinStack() {
        // Default constructor doesn't need to do anything
    }
    
    void push(int val) {
        if (st.empty()) {
            // If it's the first element, it is also the minimum
            st.push({val, val});
        } else {
            // Otherwise, compare the new value with the current minimum
            int currentMin = std::min(val, st.top().second);
            st.push({val, currentMin});
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
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