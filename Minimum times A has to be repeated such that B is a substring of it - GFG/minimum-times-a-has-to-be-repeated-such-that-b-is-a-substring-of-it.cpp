// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



// Problem : https://practice.geeksforgeeks.org/problems/5ef42ba605fff6cd60b1b2dd2ee230ade1fa25b0/1



class Solution {
public:
    int minRepeats(string A, string B) {
        int i = 0;
        while(i < A.length()) {
            if(A[i] == B[0]) {
                bool flag = true;
                int k = 1;
                for(int j=0; j<B.length(); j++) {
                    if (A[(i+j)%A.length()] != B[j]) {
                        flag = false;
                        break;
                    }
                    else if ((i+j)%A.length() == 0) k++;
                }
                if(flag)
                    return i?k:k-1;
            }
            i++;
        }
        return -1;
    }
};



// { Driver Code Starts.

int main() {
    int t;
    scanf("%d ",&t);
    while (t--) {
        string A,B;
        getline(cin,A);
        getline(cin,B);

        Solution ob;
        cout << ob.minRepeats(A,B) << endl;
    }
    return 0;
}  // } Driver Code Ends