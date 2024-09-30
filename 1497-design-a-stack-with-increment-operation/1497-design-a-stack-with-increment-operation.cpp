class CustomStack {
private:
    vector<int> stack; // Stack to hold the elements
    int maxSize;       // Maximum size of the stack

public:
    // Constructor to initialize the stack with maxSize
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
    }
    
    // Push element x onto the stack if it's not full
    void push(int x) {
        if (stack.size() < maxSize) {
            stack.push_back(x);
        }
    }
    
    // Pop the top element from the stack if it's not empty
    int pop() {
        if (stack.empty()) {
            return -1; // Stack is empty
        } else {
            int topElement = stack.back();
            stack.pop_back();
            return topElement;
        }
    }
    
    // Increment the bottom k elements of the stack by val
    void increment(int k, int val) {
        int limit = min(k, (int)stack.size()); // Increment up to the min(k, size of stack)
        for (int i = 0; i < limit; i++) {
            stack[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
