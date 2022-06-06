/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int len( ListNode *a ){
        int l = 0;
        while( a ){
            ++l;
            a = a->next;
        }
        return l;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int a = len(headA);
        int b = len(headB);
        
        while( a > b ){
            headA = headA->next;
            --a;
        }
        
        while( b > a ){
            headB = headB->next;
            --b;
        }
        
        while( headA && headB ){
            if( headA == headB ){
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        
        return NULL;
    }
};