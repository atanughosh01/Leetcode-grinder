// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



// Problem : https://practice.geeksforgeeks.org/problems/help-a-thief5938/1



class Solution {
public:
    int maxCoins(int A[], int B[], int T, int N) {
        vector<pair<int,int>> arr;
        for (int i = 0; i < N; i++)
            arr.push_back({B[i], A[i]});
        sort(arr.begin(), arr.end());
        int ans = 0;
        for(int i = N-1; i >= 0; i--) {
            int cur = min(T, arr[i].second);
            ans += (cur * arr[i].first);
            T -= cur;
        }
        return ans;
    }
};



// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int T,N;
        cin>>T>>N;
        
        int A[N], B[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];
        for(int i=0; i<N; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.maxCoins(A,B,T,N) << endl;
    }
    return 0;
}  // } Driver Code Ends