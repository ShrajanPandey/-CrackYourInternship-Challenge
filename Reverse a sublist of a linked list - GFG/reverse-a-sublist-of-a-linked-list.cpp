// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};


 // } Driver Code Ends
//User function Template for C++

/*Link list node 
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/

class Solution
{
    public:
     Node* reverse(Node* head)
    {
        if (head == NULL || head->next == NULL)
            return head;
 

        Node* rest = reverse(head->next);
        head->next->next = head;
 
        /* tricky step -- see the diagram */
        head->next = NULL;
 
        /* fix the head pointer */
        return rest;
    }
    
    Node* reverseBetween(Node* head, int m, int n)
    {   
        if( m == n ){
            return head;
        }
        
        Node *dummy = new Node(-1);
        dummy->next = head;
        
        Node *temp = dummy,*left1 = NULL , *left2 = NULL, *right2 = NULL;

        int c = 1;
        while( temp ){
            
            if( c == m ){
                left1 = temp;
            }
            if( c == n ){
                left2 = temp;
                if( temp->next ){
                    right2 = temp->next->next;
                }
                break;
            }
            
            temp = temp->next;
            ++c;
        }
        
        if( left1 == NULL || left2 == NULL || left2->next == NULL ){
            return head;
        }
        
        Node *tempHead = left1->next,*t = tempHead;
        left2->next->next = NULL;

        tempHead = reverse(tempHead);

        left1->next = tempHead;
        t->next = right2;
        
        return dummy->next;
        
    }
};

// { Driver Code Starts.

/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}



// Driver program to test above functions
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int N, m, n;
		cin >> N>>m>>n;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < N; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

		

        Solution ob;

		Node* newhead = ob.reverseBetween(head, m, n);
		printList(newhead);

		cout << "\n";



	}
	return 0;
}
  // } Driver Code Ends