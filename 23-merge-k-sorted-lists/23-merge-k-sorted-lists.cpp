/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct cmp{
  
    bool operator()(ListNode *a , ListNode *b){
        
        return a->val > b->val;
        
    }
    
};
    
class Solution {
public:

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        ListNode *dummyHead = new ListNode(0), *tail = dummyHead;
        
        priority_queue<ListNode*, vector<ListNode*> , cmp > pendingLists;
        
        for( int i = 0 ; i < lists.size() ; ++i ){
            if( lists[i] )
                pendingLists.push(lists[i]);
        }
        
        while( pendingLists.empty() != 1 ){
            
            ListNode *curNode = pendingLists.top();
            pendingLists.pop();
            
            tail->next = curNode;
            tail = curNode;
            
            if( curNode->next ){
                pendingLists.push(curNode->next);
            }
            
        }
        
        return dummyHead->next;
        
    }
};