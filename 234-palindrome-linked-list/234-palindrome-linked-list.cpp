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
    ListNode *head = NULL;
    bool check(ListNode *node ){
        
        if( node == NULL ){
            return 1;
        }
        
        bool p  = check(node->next);
        if( p == 0 ){
            return 0;
        }
        
        if( head->val != node->val ){
            return 0;
        }
        head = head->next;
        
        return 1;
        
    }
    
    bool isPalindrome(ListNode* hed) {
        head = hed;
        return check(hed);
    }
};