// { Driver Code Starts
#include <bits/stdc++.h>

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten (Node* root);

int main(void) {

	int t;
	cin>>t;
	while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			int data;
			scanf("%d",&data);
			temp = new Node(data);
			temp->next = NULL;
			temp->bottom = NULL;
			
			if(flag){
				head = temp;
				pre = temp;
				flag = 0;
				flag1 = 1;
			}
			else{
				pre->next = temp;
				pre = temp;
				flag1 = 1;
			}
			for(int j=0;j<m;j++){
				
				int temp_data;
				scanf("%d",&temp_data);
				tempB = new Node(temp_data);

				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		}
		   Node *fun = head;
		   Node *fun2=head;

            Node* root = flatten(head);
            printList(root);
            cout<<endl;

	}
	return 0;
}
// } Driver Code Ends


/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

// Node *merge(Node *a , Node *b){
    
//     if( a == NULL ){
//         return b;
//     }
//     if( b == NULL ){
//         return a;
//     }
    
//     Node *result = NULL;
//     if( a->data <= b->data ){
//         result = a;
//         a->bottom = merge(a->bottom , b);
//     }
//     else{
//         result = b;
//         b->bottom = merge(a , b->bottom);
//     }
    
//     return result;
    
// }
struct cmp{
    bool operator()(Node *a , Node *b){
        return a->data > b->data;
    }
};

Node *flatten(Node *root)
{
//   if( root == NULL ){
//       return root;
//   }
   
//   Node *smallAns = flatten(root->next);
//   return merge(root, smallAns);
   
   
    priority_queue<Node*,vector<Node*>,cmp> pq;
    Node *temp = root;
    
    while( temp ){
        pq.push(temp);
        temp = temp->next;
    }
    
    Node *ans = new Node(0),*tail = ans;
    
    while( pq.empty() != 1 ){
        
        auto k = pq.top();
        pq.pop();
        
        tail->bottom = k;
        tail = k;
        
        if( k->bottom ){
            pq.push(k->bottom);
        }
        
    }
    
    return ans->bottom;
//   Node *ans = new Node(0);
//   Node *tail = ans;
   
  
//   while( root && smallAns ){
    
//       if( root->data <= smallAns->data ){
//           tail->bottom = root;
//           tail = root;
//           root = root->bottom;
//       }
//       else{
//           tail->bottom = smallAns;
//           tail = smallAns;
//           smallAns = smallAns->bottom;
//       }
       
//   }
   
//   if( root ){
//       tail->bottom = root;
//   }
//   if( smallAns ){
//       tail->bottom = smallAns;
//   }
   
//   return ans->bottom;
   
}

