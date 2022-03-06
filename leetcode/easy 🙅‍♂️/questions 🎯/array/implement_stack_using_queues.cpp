// https://leetcode.com/problems/implement-stack-using-queues/

class MyStack {
    private:
        queue<int> firstQ;
        queue<int> secondQ;
        bool isFirstActivated=true;
        int size;
public:
    MyStack() {
        size=0;
    }
    
    void push(int x) {
        if(isFirstActivated) {
            firstQ.push(x);
        }else {
            secondQ.push(x);
        }
    }
    
    int pop() {
        if(isFirstActivated) {
            int toReturn = firstQ.back();
            while(firstQ.size()>1) {
                secondQ.push(firstQ.front());
                firstQ.pop();
            }
            firstQ.pop();
            isFirstActivated=false;
            return toReturn;
        } else {
            int toReturn = secondQ.back();
            while(secondQ.size()>1) {
                firstQ.push(secondQ.front());
                secondQ.pop();
            }
            secondQ.pop();
            isFirstActivated=true;
            return toReturn;
        }
    }
    
    int top() {
        if(isFirstActivated) {
            return firstQ.back();
        }else {
            return secondQ.back();
        }
    }
    
    bool empty() {
        cout<<firstQ.size()<<" "<<secondQ.size();
        return firstQ.empty() && secondQ.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */