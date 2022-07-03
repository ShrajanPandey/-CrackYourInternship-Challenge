/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs( Node *node , map<int,Node*> &clones , unordered_set<int> &visited ){
        
        visited.insert(node->val);
        Node *parent = clones.count(node->val) ? clones[node->val] : new Node(node->val);
        // cout << node->val << endl;
        clones[node->val] = parent;
        
        for( auto cur : node->neighbors ){
            
            bool present = 0;
            Node *newNode = clones.count(cur->val) ? clones[cur->val] : new Node(cur->val);
            // cout << cur->val << ' ';
            clones[cur->val] = newNode;
            
            for( int i = 0 ; i < parent->neighbors.size() ; ++i ){
                if( parent->neighbors[i]->val == cur->val ){
                    present = 1;
                    break;
                }
            }
            if( present == 0 ){
                parent->neighbors.push_back(newNode);
            }
            
            if( visited.count(cur->val) == 0 ){
                dfs(cur , clones , visited);
            }
            
        }
        
        // cout << endl;
    }
    
    Node* cloneGraph(Node* node) {
        
        if( node == NULL ){
            return NULL;
        }
        
        map<int,Node*> clones;   
        Node *newNode = new Node(node->val);
        
        clones[node->val] = newNode;
        unordered_set<int> visited;
        
        dfs(node , clones , visited);
        
        return newNode;
        
    }
};