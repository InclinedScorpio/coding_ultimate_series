// https://leetcode.com/problems/min-stack/

/**
 * LOGIC: must know vector push_back(), pop_back()
 * 
 */ 
class MinStack {
public:
    vector<int> stack;
    
    MinStack() {
    }
    
    void push(int val) {
        this->stack.push_back(val);
    }
    
    void pop() {
        this->stack.pop_back();
    }
    
    int top() {
        return this->stack[this->stack.size()-1];
    }
    
    int getMin() {
        int min = INT_MAX;
        for(int i: this->stack) {
            if(min>i)
                min = i;
        }
        return min;
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