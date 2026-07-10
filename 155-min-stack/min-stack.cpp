class MinStack {
    stack<int>mainstack;
    stack<int>minstack;
public:
    MinStack() {
        
    }
    
    void push(int value) {
        mainstack.push(value);
        if(minstack.empty())
        minstack.push(value);
        else minstack.push(min(minstack.top(),value));

    }
    
    void pop() {
        mainstack.pop();
        minstack.pop();

        
    }
    
    int top() {
       return mainstack.top();
    }
    
    int getMin() {
       return minstack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */