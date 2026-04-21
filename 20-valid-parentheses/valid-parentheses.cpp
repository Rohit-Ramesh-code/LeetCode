#include <stack>
#include <string>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> st;

        for (char c : s) {
            // If we see an open bracket, push its corresponding closing bracket
            if (c == '(') {
                st.push(')');
            } else if (c == '{') {
                st.push('}');
            } else if (c == '[') {
                st.push(']');
            } 
            // If it's a closing bracket, it must match the top of the stack
            else {
                // If the stack is empty (no open brackets left) OR 
                // the current bracket doesn't match the expected one on top of the stack
                if (st.empty() || st.top() != c) {
                    return false;
                }
                // If it matches, pop it off the stack
                st.pop();
            }
        }

        // If the stack is completely empty at the end, every bracket was matched!
        return st.empty();
    }
};