class MinStack {
public:
    stack<int> st;
    stack<int> min_st;
    
    MinStack() {
        while(st.empty() == false) st.pop(); 
        while(min_st.empty()==false) min_st.pop();
    }
    
    void push(int val) 
    {
        st.push(val);
        int mini=val;
        if(!min_st.empty())
        {
            mini=min(mini,min_st.top());
        }
        min_st.push(mini);
    }
    
    void pop() 
    {
        
        if(!st.empty())
        {
            st.pop();
            min_st.pop();
        }
        return;
        
    }
    
    int top() {
        if(st.empty())
            return -1;
        return st.top();     
    }
    
    int getMin() {
        
        return min_st.top();
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