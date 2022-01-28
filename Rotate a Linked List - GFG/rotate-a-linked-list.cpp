// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


 // } Driver Code Ends


// Problem : https://practice.geeksforgeeks.org/problems/rotate-a-linked-list/1


class Solution
{
    public:
    Node* rotate(Node* head, int k) {
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        int count=0;
        
        Node* temp=head;
        Node* mid=nullptr;
        Node* tail=nullptr;
        
        while(temp!=nullptr){
            if(count==k-1){
                mid=temp;
            }
            tail=temp;
            temp=temp->next;
            count++;
        }
        tail->next=head;
        head=mid->next;
        mid->next=nullptr;
        return head;
    }
};


// { Driver Code Starts.

void printList(Node *n)
{
    while (n != NULL)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, val, k;
        cin>>n;
        
        cin>> val;
        Node *head = new Node(val);
        Node *tail = head;
        
        for(int i=0; i<n-1; i++)
        {
            cin>> val;
            tail->next = new Node(val);
            tail = tail->next;
        }
        
        cin>> k;
        
        Solution ob;
        head = ob.rotate(head,k);
        printList(head);
    }
    return 1;
}
  // } Driver Code Ends