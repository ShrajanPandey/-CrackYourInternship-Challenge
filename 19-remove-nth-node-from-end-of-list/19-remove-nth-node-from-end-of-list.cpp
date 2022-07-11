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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if( head == NULL ){
            return head;
        }
        
        ListNode *start = head,*second = head;
        
        for( int i = 0 ; i < n-1 ; ++i ){
            start = start->next;
        }
        
        ListNode *pre = NULL;
        while( start->next ){
            pre = second;
            start = start->next;
            second = second->next;
        }
        
        if( pre == NULL ){
            return second->next;
        }
        pre->next = second->next; return head;
        
    }
    
};
