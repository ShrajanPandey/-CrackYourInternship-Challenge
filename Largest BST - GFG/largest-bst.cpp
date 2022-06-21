// { Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
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
/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution{
    public:
    
    class bstNode{
        
        public:
        int maxVal;
        int minVal;
        bool isbst;
        int size;
        
        bstNode(int maxVal , int minVal ,int size){
            size = size;
            maxVal = maxVal;
            minVal = minVal;
            isbst = 1;
        }
        
        bstNode(){
            maxVal = INT_MIN;
            minVal = INT_MAX;
            size = 0;
            isbst = 1;
        }
        
    };
    
    int fans = 0;
    bstNode isBST(Node *root, int &s){
        
        bstNode ans;        
        if( root == NULL ){
            return ans;
        }
   
        int size = 0;
        bstNode left = isBST(root->left, size);
        bstNode right = isBST(root->right,size);
        
        ans.size = size+1;
        s += size+1;
        
        if( left.isbst && right.isbst && left.maxVal < root->data && right.minVal > root->data ){
            fans = max( fans , size+1);
            ans.isbst = 1;
        }
        else{
            ans.isbst = 0;
        }
        
        ans.maxVal = max(left.maxVal,max(root->data,right.maxVal));
        ans.minVal = min(left.minVal,min(root->data,right.minVal));
        
        return ans;
        
    }
    
    int largestBst(Node *root)
    {
        
        fans = 1;
        int s =0;
        bstNode ans = isBST(root,s);
        if( ans.isbst ){
            fans = max(fans, s);
        }
        
        return fans;
        
    }
};

// { Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.largestBst(root) << endl;
    }
    return 0;
}
  // } Driver Code Ends