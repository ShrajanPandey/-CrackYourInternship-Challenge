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
    stack<int> s;
    vector<int> ans;
    
    void insertCurAns( int val ){
        
        int value = 0;
        while( s.empty() != 1 && s.top() <= val ){
            s.pop();
        }
        
        if( s.empty() != 1 ){
            value = s.top();
        }
        
        s.push(val);
        ans.push_back(value);
        
    }
    
    void insert( ListNode *head ){
        
        if( head == NULL ){
            return ;
        }
        
        insert( head->next );
        
        insertCurAns(head->val);
        
    }
    
    vector<int> nextLargerNodes(ListNode* head) {
        
        ans.clear();
        insert(head);
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};