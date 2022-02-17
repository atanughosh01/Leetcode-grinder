// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


// Problem : https://practice.geeksforgeeks.org/problems/47e5aa3f32aee9e0405f04960f37c8a562d96a2f/1


class Solution {
 public:
    void prank(long long a[], int n){
        long long int temp[n];
        for(int i=0; i<n; i++) {
            if(a[i] == i)
               temp[i] = i;
            else
                temp[i] = a[a[i]];
        }
        for(int i=0;i<n;i++) 
            a[i] = temp[i];
       return;
    }
};


// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        long long a[n];
        for(int i = 0 ;i<n;i++){
            cin>>a[i];
        }
        Solution ob;
        ob.prank(a,n);

        for(int i = 0;i<n;i++)
            cout<<a[i]<<" ";
        cout<<"\n";
    }
}

  // } Driver Code Ends