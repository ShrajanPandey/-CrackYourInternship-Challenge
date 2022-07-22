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
        //Creating New Node With Some value saves us from a lot of edge work cases handling :)
        ListNode *node1 = new ListNode(-1), *node2 = new ListNode(-1);
        ListNode *less = node1 , *more = node2;
        
        ListNode *temp = head;
        while( temp ){
            if( temp->val < x ){
                less->next = temp;
                less = temp;
            }
            else{
                more->next = temp;
                more = temp;
            }
            temp = temp->next;
        }
        
        more->next = NULL;
        less->next = node2->next;
        return node1->next;
        
    }
};