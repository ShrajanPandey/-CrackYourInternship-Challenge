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
    
    ListNode *reverse( ListNode *head ){
        
        ListNode *pre = NULL , *cur = head , *temp = NULL;
        
        while( cur != NULL ){
            
            temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
            
        }
        
        return pre;
        
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if( head == NULL ){
            return head;
        }
        
        if( left == right ){
            return head;
        }
        
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode *pre = dummy , *cur = dummy;
        
        for( int i = 0 ; i < left ; ++i ){
            ListNode *temp = cur->next;
            pre = cur;
            cur = temp;
        }

        ListNode *leftPre = pre , *start = cur, *nextRight = NULL;
        pre = NULL;
        
        for( int i = 0 ; i < right - left + 1 ; ++i ){
            
            ListNode *temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
            
        }
        
        leftPre->next = pre;
        start->next = cur;
        
        
        return dummy->next;
        
        
    }
};