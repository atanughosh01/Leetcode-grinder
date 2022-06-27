// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



// Problem : https://practice.geeksforgeeks.org/problems/sum-of-elements-between-k1th-and-k2th-smallest-elements3133/1



/*
    class Solution{
    public:
        long long sumBetweenTwoKth(long long *A, long long N, long long K1, long long K2) {
            sort(A, A + N);
            return accumulate(A + K1, A + K2 - 1, 0);
        }
    };
*/


class Solution{
public:
    long long sumBetweenTwoKth(long long *A, long long N, long long K1, long long K2) {
        partial_sort(A, A + K2 - 1, A + N) ;
        long long ans = 0 ;
        for(int i = K1; i < K2 - 1; i++) ans += A[i] ;
        return ans;
    }
};



// { Driver Code Starts.
int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        cin>>n;
        long long a[n+5];
        for(int i =0;i<n;i++)
            cin >> a[i];
        
        long long k1, k2;
        cin >> k1 >> k2;
        Solution ob;
        cout << ob.sumBetweenTwoKth(a, n, k1, k2) << endl;
        
    }
	return 0;
}
  // } Driver Code Ends