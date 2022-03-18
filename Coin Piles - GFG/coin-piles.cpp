// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



// Problem : https://practice.geeksforgeeks.org/problems/coin-piles5152/1



class Solution {
public:
    int minSteps(int A[], int N, int K) {
        sort(A, A+N);
        int prefixSum[N+1];
        memset(prefixSum,0,sizeof(prefixSum));
        for(int i=1; i<=N; i++) {
            prefixSum[i] = prefixSum[i-1] + A[i-1];
        }
        int ans = INT_MAX;
        for(int i=0; i<N; i++) {
            int idx = upper_bound(A, A+N, A[i]+K) - A;
            int greaterElementsSum = prefixSum[N]-prefixSum[idx];
            int reducedBy = (N-idx) * (A[i]+K);
            int coinsRemoved = greaterElementsSum-reducedBy;
            coinsRemoved += (prefixSum[i]);
            ans = min(ans,coinsRemoved);
        }
        return ans;
    }
};



// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin>>N>>K;
        
        int A[N];
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.minSteps(A,N,K) << endl;
    }
    return 0;
}  // } Driver Code Ends