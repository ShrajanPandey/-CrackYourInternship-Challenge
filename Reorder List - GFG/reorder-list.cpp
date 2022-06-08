// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void reorderList(struct Node* head);

/* Function to create a new Node with given data */
struct Node* newNode(int data) {
    struct Node* new_Node = new Node(data);
    new_Node->data = data;
    new_Node->next = NULL;
    return new_Node;
}

void printList(struct Node* Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {

        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void) {
    int t, n, m, i, x;

    cin >> t;
    while (t--) {
        struct Node* temp, *head;
        cin >> n;
        cin >> x;
        head = new Node(x);
        temp = head;
        for (i = 0; i < n - 1; i++) {
            cin >> x;
            temp->next = new Node(x);
            temp = temp->next;
        }

        reorderList(head);
        printList(head);
        freeList(head);
    }
    return 0;
}
// } Driver Code Ends


/* Following is the Linked list node structure */

/*
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

Node* reverse(Node *head)
{
    // Initialize current, previous and next pointers
    Node* current = head;
    Node *prev = NULL, *next = NULL;

    while (current != NULL) {
        // Store next
        next = current->next;
        // Reverse current node's pointer
        current->next = prev;
        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    head = prev;
    
    return head;
    
}

void reorderList(Node* head) {
    
    if( head == NULL || head->next == NULL ){
        return;
    }
    
    Node *slow = head , *fast = head->next;
    while( fast && fast->next ){
        
        slow = slow->next;
        fast = fast->next->next;
        
    }
    
    Node *temp = slow->next;
    slow->next = NULL;
    temp = reverse(temp);
    
    Node *ansHead = new Node(0), *ansTail = ansHead;
    
    bool a = 1;
    while( head || temp ){
        
        if( a ){
            ansTail->next = head;
            ansTail = head;
            head = head->next;
            a = 0;
        }
        else{
            ansTail->next = temp;
            ansTail = temp;
            temp = temp->next;
            a = 1;
        }
        
    }
    
    head = ansHead->next;
    
}