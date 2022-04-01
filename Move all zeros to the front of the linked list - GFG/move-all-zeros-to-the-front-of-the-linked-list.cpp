// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void push(struct Node **head_ref, int new_data) {
    struct Node *new_node = new Node(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void moveZeroes(struct Node **head);

// function to displaying nodes
void display(struct Node *head) {
    while (head != NULL) {
	    cout << head->data << " ";
	    head = head->next;
    }
    cout <<endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int q;
        struct Node *Head=NULL;
        for(int i=0;i<n;i++)
        {
            cin>>q;
            push(&Head,q);
        }
        moveZeroes(&Head);
        display(Head);

    }
}
// } Driver Code Ends



// Problem : https://practice.geeksforgeeks.org/problems/move-all-zeros-to-the-front-of-the-linked-list/1



void moveZeroes(struct Node **head) {
    Node *curr = *head;
    Node *zhead = new Node(-1);
    Node *dummy =zhead;
    Node *nhead = new Node(-1);
    Node *prev = nhead;
    while(curr) {
        if(curr->data == 0) {
           Node *newnode = new Node(0);
           dummy->next = newnode;
           dummy = newnode;
        } else {
           Node *newnode = new Node(curr->data);
           prev->next = newnode;
           prev = newnode;
        }
       curr = curr->next;
    }
    dummy->next = nhead->next;
    *head = zhead->next;
}
