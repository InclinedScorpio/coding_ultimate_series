// https://leetcode.com/problems/implement-queue-using-stacks/

class MyQueue {
public:
    
    stack<int> input, output;
    
    MyQueue() {}
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        int toReturn = peek();
        output.pop();
        return toReturn;
    }
    
    int peek() {
        if(output.empty()) {
            while(!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        int toReturn = output.empty() ? -1 : output.top();
        return toReturn;
    }
    
    bool empty() {
        if(input.empty() && output.empty()) return true;
        return false;
    }
};
