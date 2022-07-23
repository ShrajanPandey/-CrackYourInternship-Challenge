class MinStack {
public:
    vector<int> st;
    multiset<int> m;
    
    MinStack() {
        
    }
    
    void push(int val) {
        st.push_back(val);
        m.insert(val);
    }
    
    void pop() {
        int x = st.back();
        m.erase(m.find(x));
        st.pop_back();
    }
    
    int top() {
        return st.back();
    }
    
    int getMin() {
        return *m.begin();
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