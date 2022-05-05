class MyStack {
public:
    queue<int> a,b;
    int to;
    
    MyStack() {
        
    }
    
    void push(int x) {
        a.push(x);
        to = x;
    }
    
    int pop() {
        while( a.size() != 1 ){
            b.push(a.front());
            a.pop();
        }
        
        int ans = a.front();
        a.pop();
  
        int l = 0;
        while( b.size() != 0 ){
            if( b.size() == 1 ){
                to = b.front();
                l = 1;
            }
            a.push(b.front());
            b.pop();
        }
        if( l == 0 ){
            to = 0;
        }
        return ans;
    }
    
    int top() {
        return to;
    }
    
    bool empty() {
        return a.size() == 0;
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