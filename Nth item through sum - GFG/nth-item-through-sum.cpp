// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



// Problem : https://practice.geeksforgeeks.org/problems/nth-item-through-sum3544/1



class Solution {
public:
    int nthItem(int L1, int L2, int A[], int B[], int N) {
        set<int> s;
        for (int i=0; i<L1; i++) {
            for (int j=0; j<L2; j++) {
               s.insert(A[i] + B[j]);
            }
        }
        for(auto itr : s) {
            if (N == 1)
                return itr;
            N--;
        }
        return -1;
    }
};



// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int L1, L2, N;
        cin>>L1>>L2;
        int A[L1], B[L2];
        for(int i = 0;i < L1;i++)
            cin>>A[i];
        for(int i = 0;i < L2;i++)
            cin>>B[i];
        cin>>N;
        
        Solution ob;
        cout<<ob.nthItem(L1, L2, A, B, N)<<endl;
    }
    return 0;
}  // } Driver Code Ends