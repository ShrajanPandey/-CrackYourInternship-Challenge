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
    
    vector<int> nextLargerNodes(ListNode* head) {
        
        vector<int> res , stk;
        
        for( ListNode *curNode = head ; curNode != NULL ; curNode = curNode->next ){
            
            while( stk.size() && res[stk.back()] < curNode->val ){
                res[stk.back()] = curNode->val;
                stk.pop_back();
            }
            
            stk.push_back(res.size());
            res.push_back(curNode->val);
            
        }
        
        for( int i = 0 ; i < stk.size() ; ++i ){
            res[stk[i]] =0;
        }
        
        return res;
        
    }
};