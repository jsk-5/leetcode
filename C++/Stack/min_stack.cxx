// https://leetcode.com/problems/min-stack/
class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        // cout << val << endl;
        stck.push(val);
        if(min_stck.empty()){
            // cout << "Min val updated:" << val << endl;
            min_stck.push(val);
        } else if (min_stck.top() >= val ){
            // cout << "Min val updated:" << val << endl;
            min_stck.push(val);
        }
    }
    
    void pop() {
        if(stck.top() == min_stck.top()){
            min_stck.pop();
        }
        stck.pop();
        
    }
    
    int top() {
        return stck.top();
        
    }
    
    int getMin() {
        return min_stck.top();
    }
private:
    stack<int> stck;
    stack<int> min_stck;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */