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
        
        ListNode *temp = dummy, *preLeft = NULL , *Left = NULL , *Right = NULL , *afterRight = NULL;
        
        int count = 1;
        while( temp != NULL ){
            
            if( count == left ){
                preLeft = temp;
                Left = temp->next;
            }    
            if( count == right+1 ){
                Right = temp;
                afterRight = temp->next;
                break;
            }
            
            temp = temp->next;
            ++count;
            
        }
        
        Right->next = NULL;
        reverse(Left);
        
        Left->next = afterRight;
        preLeft->next = Right;
        
        return dummy->next;
        
        
    }
};