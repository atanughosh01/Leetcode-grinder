// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



// Problem : https://practice.geeksforgeeks.org/problems/bike-racing0543/1



class Solution{
public:
    long buzzTime(long N, long M, long L, long H[], long A[]) {
        long low = 0, high = max(L, M), ans = 0;
        while (low <= high) {
            long fast = 0, mid = low + (high - low)/2;
            for (long i=0; i<N; i++) {
                if ((H[i] + A[i]*mid) >= L) {
                    fast += (H[i] + A[i]*mid);
                }
            }
            if (fast >= M) {
                ans = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        return ans;
    }
};



// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long N, M, L;
        cin>>N>>M>>L;
        long H[N], A[N];
        for(long i = 0;i < N;i++) 
            cin>>H[i]>>A[i];
        
        Solution ob;
        cout<<ob.buzzTime(N, M, L, H, A)<<"\n";
    }
    return 0;
}  // } Driver Code Ends