// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



// Problem : https://practice.geeksforgeeks.org/problems/d6e88f06b273a60ae83992314ac514f71841a27d/1



class Solution {
 public:
    int smallestSubstring(string S) {
       int n = (int)(S.size());
       int a = -1, b = -1, c = -1;
       int res = INT_MAX;
       if(n >= 3)
       for(int i=0; i<n; i++) {
           if(S[i] == '0') a = i;
           if(S[i] == '1') b = i;
           if(S[i] == '2') c = i;
           if(a != -1 && b != -1 && c != -1)
              res = min(res, max(a, max(b,c)) - min(a, min(b,c)) + 1);
       }
       return res == INT_MAX ? -1 : res;
    }
};



// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}  // } Driver Code Ends