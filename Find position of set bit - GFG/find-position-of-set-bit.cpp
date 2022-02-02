// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


// Problem : https://practice.geeksforgeeks.org/problems/find-position-of-set-bit3706/1


class Solution {
public:
    int findPosition(int N) {
        int cnt=0,pos=0;
        while(N){
            int rem = N%2;
            pos++;
            N /= 2;
            if(rem==1)
                cnt++;
        }
        return cnt==1? pos: -1;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin>>N;

        Solution ob;
        cout << ob.findPosition(N) << endl;
    }
    return 0;
}  // } Driver Code Ends