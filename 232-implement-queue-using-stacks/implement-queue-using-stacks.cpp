#include <stack>

class MyQueue {
private:
    std::stack<int> s1; // Input stack
    std::stack<int> s2; // Output stack

    // Helper function to move elements from s1 to s2 when s2 is empty
    void transferIfNeeded() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
    }

public:
    MyQueue() {
        // Default constructor doesn't need to do anything since std::stack initializes itself
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        transferIfNeeded();
        int topElement = s2.top();
        s2.pop();
        return topElement;
    }
    
    int peek() {
        transferIfNeeded();
        return s2.top();
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */