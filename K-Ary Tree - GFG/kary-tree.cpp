// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



// Problem : https://practice.geeksforgeeks.org/problems/k-ary-tree1235/1



class Solution {
public:
    long long int m=1e9+7;
    long long karyTree(int k, int h) {
        if(h==1)
            return k;
        long long int res = karyTree(k,h/2);
        if(h%2==0)
            return (res%m*res%m)%m;
        else {
            long long int x = (res%m*res%m)%m;
            return (x%m*k%m)%m;
        }
    }
};



// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int k,m;
        
        cin>>k>>m;

        Solution ob;
        cout << ob.karyTree(k,m) << endl;
    }
    return 0;
}  // } Driver Code Ends