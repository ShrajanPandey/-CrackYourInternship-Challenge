// { Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};



 // } Driver Code Ends
/* Node structure

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution
{
    public:
    void rearrangeEvenOdd(Node *head)
    {
        if( head == NULL ){
            return;
        }
        
       Node *odd = new Node(0), *even = new Node(0);
       Node *otail = odd , *etail = even;
       Node *temp = head;
       
       int no = 1;
       while( temp != NULL ){
        
            if( no&1 ){
                otail->next = temp;
                otail = temp;
            }
            else{
                etail->next = temp;
                etail = temp;
            }
            ++no;
            temp = temp->next;
            
       }
        
        etail->next = NULL;
        
      otail->next = even->next;
      head = odd->next;
       
    }
};


// { Driver Code Starts.

/* Driver program to test above function*/
int main()
{
    int T,i,n,l;

    cin>>T;

    while(T--)
    {
        struct Node *head = NULL;
        struct Node *temp = head;
        cin>>n;
        for(i=1; i<=n; i++)
        {
            cin>>l;

            if (head == NULL)
            {   
                head = temp = new Node(l); 
                
            }
            else
            {  temp->next = new Node(l);
               temp = temp->next;
            }
        }
        Solution ob;
        ob.rearrangeEvenOdd(head);
        while(head != NULL)
        {
            printf("%d ", head->data);
            head = head->next;
        }
        printf("\n");
    }
    return 0;
}
  // } Driver Code Ends