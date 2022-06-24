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
class Solution {
public:
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if( head == NULL ){
            return head;
        }
        
        if( left == right ){
            return head;
        }
        
        ListNode *fakeHead = new ListNode(0), *pre = fakeHead ;
        fakeHead->next = head;
        
        for( int i = 0 ; i < left-1 ; ++i ){
            
            pre = pre->next;
            
        }
        
        ListNode *start = pre->next,*after = start->next;
        
        for( int i = 0 ; i < right-left ; ++i ){
            start->next = after->next;
            after->next = pre->next;
            pre->next = after;
            after = start->next;
        }
        
        
        return fakeHead->next;
        
    }
};