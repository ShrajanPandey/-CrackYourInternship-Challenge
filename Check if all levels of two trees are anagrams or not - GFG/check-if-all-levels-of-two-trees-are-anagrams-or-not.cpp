// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool areAnagrams(Node *root1, Node *root2)
    {
    
        queue<Node *> pendingNodes1,pendingNodes2;
        pendingNodes1.push(root1);
        pendingNodes2.push(root2);
        
        while( pendingNodes1.empty() == 0 && pendingNodes2.empty() == 0 ){
            
            int size1 = pendingNodes1.size(), size2 = pendingNodes2.size();
            if( size1 != size2 ){
                return false;
            }
            
            map<int,int> values;
            for( int i = 0 ; i < size1 ; ++i ){
                
                Node *curNode = pendingNodes1.front();
                pendingNodes1.pop();
                
                values[curNode->data]++;
                
                if( curNode->left ){
                    pendingNodes1.push(curNode->left);
                }
                if( curNode->right ){
                    pendingNodes1.push(curNode->right);
                }
                
            }
            
            for( int i = 0 ; i < size2 ; ++i ){
                
                Node *curNode = pendingNodes2.front();
                pendingNodes2.pop();
                
                if( values.count(curNode->data) ){
                    
                    values[curNode->data]--;
                    if( values[curNode->data] == 0 ){
                        values.erase(curNode->data);
                    }
                    
                }
                else{
                    return false;
                }
                
                if( curNode->left ){
                    pendingNodes2.push(curNode->left);
                }
                if( curNode->right ){
                    pendingNodes2.push(curNode->right);
                }
                
            }
            
        }
        
        if( pendingNodes1.size() == 0 && pendingNodes2.size() == 0 ){
            return true;
        }
        
        return false;
        
    }
};

// { Driver Code Starts.

/* Driver program to test size function*/
int main() {
    int t;
    scanf("%d\n", &t);
    while (t--) {
        string treeString1, treeString2;
        getline(cin, treeString1);
        Node *root1 = buildTree(treeString1);
        getline(cin, treeString2);
        Node *root2 = buildTree(treeString2);
        Solution ob;
        cout << ob.areAnagrams(root1, root2) << endl;
    }
    return 0;
}
  // } Driver Code Ends