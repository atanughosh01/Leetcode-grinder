// { Driver Code Starts
#include <iostream>

using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};



Node *swapkthnode(Node* head, int num, int K);

void addressstore(Node **arr, Node* head)
{
    Node* temp = head;
    int i = 0;
    while(temp){
        arr[i] = temp;
        i++;
        temp = temp->next;
    }
}

bool check(Node ** before, Node **after, int num, int K)
{
    if(K > num)
        return 1;
    return (before[K-1] == after[num - K]) && (before[num-K] == after[K-1]);
}

int main()
{
    int T;
    cin>>T;
    while(T--){
        int num, K , firstdata;
        cin>>num>>K;
        int temp;
        cin>>firstdata;
        Node* head = new Node(firstdata);
        Node* tail = head;
        for(int i = 0; i<num - 1; i++){
            cin>>temp;
            tail->next = new Node(temp);
            tail = tail->next;
        }
        
        Node *before[num];
        addressstore(before, head);
        
        head = swapkthnode(head, num, K);
        
        Node *after[num];
        addressstore(after, head);
        
        if(check(before, after, num, K))
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
}
// } Driver Code Ends



// Problem : https://practice.geeksforgeeks.org/problems/swap-kth-node-from-beginning-and-kth-node-from-end-in-a-singly-linked-list/1



Node *swapkthnode(Node* head, int num, int K) {
    if(K>num) return head;
    Node *left, *right, *trav=head, *leftprev=NULL, *rightprev=NULL;
    int i=0;
    while(++i<K && trav) {
        leftprev = trav;
        trav = trav->next;
    }
    left = trav;
    i=0;
    trav = head;
    while(++i <= (num-K) && trav){ 
        rightprev = trav;
        trav = trav->next;
    }
    right = trav;
    if(!leftprev) head=right;
    else leftprev->next = right;
    if(!rightprev) head = left;
    else rightprev->next = left;
    swap(right->next,left->next);
    return head;
}
