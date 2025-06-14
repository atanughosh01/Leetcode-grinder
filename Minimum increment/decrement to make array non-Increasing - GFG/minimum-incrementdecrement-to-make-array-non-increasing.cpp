// { Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>

using namespace std;



 // } Driver Code Ends



// Problem : https://practice.geeksforgeeks.org/problems/bf249fb32af71fc4e294b123d99e668a91652be4/1



class Solution{
public:
    int minOperations(int *a, int n) {
        int count = 0;
		priority_queue<int ,vector<int>, greater<int>>pq; 
		for (int i = 0; i < n; i++) { 
			if (!pq.empty() && pq.top() < a[i]) {
				count += a[i] - pq.top();
				pq.push(a[i]);
				pq.pop();
			}
			pq.push(a[i]); 
		} 
		return count; 
    }
};



// { Driver Code Starts.

int main() {
    
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int  a[n+1];
        for(int i=0;i<n;i++)
            cin>>a[i];
            
        Solution ob;
        cout<<ob.minOperations(a,n)<<endl;
    }
    
	return 0;
}  // } Driver Code Ends