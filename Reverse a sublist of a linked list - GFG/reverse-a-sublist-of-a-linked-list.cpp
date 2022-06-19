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



// Problem : https://practice.geeksforgeeks.org/problems/reverse-a-sublist-of-a-linked-list/1



class Solution {
public:
    Node *reverseBetween(Node *head, int m, int n) {
        Node *curr = head;
        Node *t = NULL;
        bool flag = false;
        Node *dummy = new Node(-1);
        Node *temp = dummy;
        int cnt = 1;
        while (cnt < m) {
            t = curr;
            curr = curr->next;
            ++cnt;
        }
        while (cnt <= n) {
            Node *newNode = new Node(curr->data);
            temp->next = newNode;
            temp = temp->next;
            ++cnt;
            curr = curr->next;
        }
        Node *p = dummy->next;
        Node *prev = NULL, *next = NULL, *x = NULL;
        while (p) {
            next = p->next;
            p->next = prev;
            prev = p;
            if (x == NULL) x = p;
            p = next;
        }
        if (t != NULL) t->next = prev;
        if (t == NULL) head = prev;
        x->next = curr;
        return head;
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