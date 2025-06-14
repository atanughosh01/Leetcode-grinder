// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int coeff;
    int pow;
    struct Node* next;
    
    Node(int c, int p){
        coeff = c;
        pow = p;
        next = NULL;
    }
    
};


void append(struct Node** head_ref, struct Node **tail_ref,
            int new_data, int new_data1)
{
    struct Node* new_node = new Node(new_data, new_data1);
    
    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

void printList(struct Node *head)
{
    struct Node *temp = head;
    
    while (temp != NULL)
    {
       printf("%d %d ", temp->coeff, temp->pow);
       temp  = temp->next;
    }
}

Node* addPolynomial(Node *p1, Node *p2);


void create_node(int x, int y, struct Node **temp)
{
    struct Node *r, *z;
    z = *temp;
    if(z == NULL)
    {
        r = new Node(x, y);
        *temp = r;
        r->next = NULL;
    }
    else
    {
        r->next = new Node(x, y);
        r = r->next;
        r->next = NULL;
    }
}
 

/* Driver program to test above function*/

 // } Driver Code Ends



// Problem : https://practice.geeksforgeeks.org/problems/polynomial-addition/1



class Solution {
public:
    Node* addPolynomial(Node *p1, Node *p2) {
        if (!p1) return p2;
        if (!p2) return p1;
        Node* curr1 = (p1->pow >= p2->pow) ? p1 : p2;
        Node* curr2 = (p1->pow >= p2->pow) ? p2 : p1;
        Node* prev = NULL;
        while (curr1 && curr2) {
            if (curr1->pow == curr2->pow) {
                curr1->coeff += curr2->coeff;
                prev = curr1;
                curr1 = curr1->next;
                curr2 = curr2->next;
            } else if (curr1->pow > curr2->pow) {
                prev = curr1;
                curr1 = curr1->next;
            } else {
                if (prev) prev->next = curr2;
                prev = curr2;
                Node* next = curr2->next;
                curr2->next = curr1;
                curr2 = next;
            }
        }
        while (curr2) {
            prev->next = curr2;
            prev = prev->next;
            curr2 = curr2->next;
        }
        return (p1->pow >= p2->pow) ? p1 : p2;
    }
};



// { Driver Code Starts.
int main()
{
    
    int t;
    cin>>t;
    while(t--)
    {
        struct Node *poly1 = NULL, *poly2 = NULL, *poly = NULL;
        struct Node *tail1  = NULL,*tail2 = NULL;
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int x,y;
            cin>>x>>y;
            	append(&poly1,&tail1,x,y);
        }
        
         int m;
        cin>>m;
        for(int i=0;i<m;i++)
        {
            int x,y;
            cin>>x>>y;
            	append(&poly2,&tail2,x,y);
        }
        Solution obj;
        Node *sum = obj.addPolynomial(poly1,poly2);
        for(Node* ptr=sum ; ptr ; ptr=ptr->next  )
        {
            // printing polynomial
            cout<< ptr->coeff << "x^" << ptr->pow;
            if(ptr->next) cout<<" + ";
        }
        cout<<endl;
       
    }

}
  // } Driver Code Ends