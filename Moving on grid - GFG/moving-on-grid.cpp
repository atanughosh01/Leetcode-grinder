// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



// Problem : https://practice.geeksforgeeks.org/problems/moving-on-grid1135/1



class Solution {
public:
    string movOnGrid(int r, int c) {
        r = (r - 1) % 7;
        c = (c - 1) % 4 ;
        if (r != c)
            return "JON";
        return "ARYA";
    }
};



// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int r, c;
        cin >> r >> c;
        Solution ob;
        cout<<ob.movOnGrid(r,c)<<endl;
    }
    return 0;
}
  // } Driver Code Ends