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
    ListNode* partition(ListNode* head, int x) {
        
        ListNode *dless = new ListNode(0) , *dmore = new ListNode(0);
        ListNode *tail1 = dless , *tail2 = dmore;
        
        ListNode *temp = head;
        while( temp != NULL ){
            
            if( temp->val >= x ){
                tail2->next = temp;
                tail2 = temp;
            }
            else{
                tail1->next = temp;
                tail1 = temp;
            }
            
            temp = temp->next;
            
        }
        
        tail1->next = dmore->next;
        tail2->next = NULL;
        
        return dless->next;
        
    }
};