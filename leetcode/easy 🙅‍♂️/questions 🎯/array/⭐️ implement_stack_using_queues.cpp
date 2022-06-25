// https://leetcode.com/problems/implement-stack-using-queues/


/**
 * LOGIC: Other than code below, there is a better way of doing this using only a single queue
 * - While insertion just reverse the queue and it will act as a stack! (Scroll down for the code!)
 * 
 */ 
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
        return firstQ.empty() && secondQ.empty();
    }
};

/**
 * 
 * Better way of doing it!
 * 
 */ 

class MyStack {
public:
    queue<int> q;
    
    MyStack() {}
    
    void push(int x) {
        q.push(x);
        for(int i=0;i<q.size()-1;i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int popVal = q.empty() ? -1 : q.front();
        q.pop();
        return popVal;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};