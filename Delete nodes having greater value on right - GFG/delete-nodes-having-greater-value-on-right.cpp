// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



 // } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    Node *compute(Node *head )
    {
        
        if( head == NULL ){
            return head;
        }
        
        stack<Node *> newLLNodes;
        
        while( head ){
            if( newLLNodes.empty() ){
                newLLNodes.push(head);
            }
            else{
                while( newLLNodes.empty() == 0 && newLLNodes.top()->data < head->data ){
                    newLLNodes.pop();
                }
                newLLNodes.push(head);
            }
            head = head->next;
        }
        
        Node *pre = NULL , *cur = NULL;
        while( newLLNodes.empty() == 0 ){
            
            cur = newLLNodes.top();
            newLLNodes.pop();
            cur->next = pre;
            pre = cur;
            
        }
        
        return cur;
        
    }
    
};
   


// { Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}
  // } Driver Code Ends