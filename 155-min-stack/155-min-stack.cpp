class Node{
    public:
    int val;
    int minVal;
    Node *next;
    
    Node(int v , int m , Node *n ){
        val = v;
        minVal = m;
        next = n;
    }
};

class MinStack {
public:
    
    Node *head;
    
    MinStack() {
        head = NULL;
    }
    
    void push(int val) {
        if(head == NULL ){
            head = new Node(val , val , NULL);
        }
        else{
            head = new Node(val , min( val , head->minVal) , head );
        }
    }
    
    void pop() {
        head = head->next;
    }
    
    int top() {
        return head->val;
    }
    
    int getMin() {
        return head->minVal;
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