
class MyLinkedList {
public:
    int size;
    vector<ListNode *> myList;
    
    MyLinkedList() {
        size = 0;
        myList.resize(20000,NULL);
    }
    
    int get(int index) {
        
        if( index >= size ){
            return -1;
        }
           
        if( myList[index] == NULL ){
            return -1;
        }
        return myList[index]->val;
        
    }
    
    void addAtHead(int val) {
        
        ListNode *newNode = new ListNode(val);
        ++size;
        if( size == 1 ){
            myList[0] = newNode;
        }
        else{
            for( int i = size-1 ; i >= 1 ; --i ){
                myList[i] = myList[i-1];
            }
            myList[0] = newNode;
            newNode->next = myList[1];
        }
        
    }
    
    void addAtTail(int val) {
        
        ++size;
        ListNode *newNode = new ListNode(val);
        myList[size-1] = newNode;

        if( size > 1 ){
            myList[size-2]->next = newNode;
        }
        
    }
    
    void addAtIndex(int index, int val) {
        
        if( index > size ){
            return;
        }
        
        if( index == size ){
            addAtTail(val);
            return;
        }
        if( index == 0 ){
            addAtHead(val);
            return;
        }
        
        ListNode *newNode = new ListNode(val);
        ++size;
        
        myList[index-1]->next = newNode;
        newNode->next = myList[index+1];
        
        for( int i = size-1 ; i > index ; --i ){
            myList[i] = myList[i-1];
        }
        
        myList[index] = newNode;
        
    }
    
    void deleteAtIndex(int index) {
        
        if( index >= size ){
            return;    
        }

        if( index == size-1 ){
            if( index != 0 ){
                myList[index-1]->next = NULL;
            }
        }
        
        for( int i = index ; i < size-1 ; ++i ){
            myList[i] = myList[i+1];
        }
        --size;
        
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */