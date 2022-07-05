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
    Node* cloneGraph(Node* node) {
        
        if( node == NULL ){
            return node;
        }
        unordered_map<Node*,Node*> clones;
        
        queue<Node*> todo;
        todo.push(node);
        
        while( todo.empty() != 1 ){
            
            Node *curNode = todo.front();
            todo.pop();
            
            if( clones.count(curNode) == 0 ){
                clones[curNode] = new Node(curNode->val);
            }
            
            for( Node *neighbour : curNode->neighbors ){
                
                if( clones.count(neighbour) == 0 ){
                    clones[neighbour] = new Node(neighbour->val);
                    todo.push(neighbour);
                }
                clones[curNode]->neighbors.push_back(clones[neighbour]);
                
            }
            
        }
        
        return clones[node];
        
    }
};