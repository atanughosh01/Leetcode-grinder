// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



// Problem : https://practice.geeksforgeeks.org/problems/228d0aa9f26db93ee5b2cb3583dbd4b197447e16/1



class Solution {
public:
    int findTime(string S1, string S2) {
        int sum = 0, j = 0;
        int arr[26] = {0};
        for(int i=0; i<S1.length(); i++) {
            arr[S1[i] - 'a'] = i;
        }
        for(int i=0; i<S2.length(); i++) {
            sum += abs(arr[S2[i] - 'a'] - arr[S1[j]-'a']);
            j = abs(arr[S2[i] - 'a']);
        }
        return sum;
    }
};



// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S1,S2;
        cin>>S1;
        cin>>S2;

        Solution ob;
        cout<<ob.findTime(S1,S2)<<endl;
    }
    return 0;
}  // } Driver Code Ends