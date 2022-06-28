// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



// Problem : https://practice.geeksforgeeks.org/problems/jump-game/1



class Solution {
public:
    int canReach(int *a, int n) {
        int max_idx = 0 ;
        for (int i = 0; i < n ; i++){
            if (max_idx < i)
                return 0 ;
            max_idx = max(max_idx, i + a[i]) ;
        }
        return 1; 
    }
};



// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.canReach(A,N) << endl;
    }
    return 0;
}  // } Driver Code Ends