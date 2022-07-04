// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



// {roblem : https://practice.geeksforgeeks.org/problems/x-xor-a-is-minimum-and-set-bits-in-x-b/1



/*
    class Solution {
    public:
        int minVal(int a, int b) {
            int x = __builtin_popcount(a), 
                y = __builtin_popcount(b),
                c = x - y, k = 0;
            int i = (c < 0) ? 1 : -1, j = (c < 0) ? 0 : 1;
            while (c) {
                if (((a>>k)&1) == j) {
                    if (j == 1) a ^= (1<<k);
                    else a |= (1<<k);
                    c += i;
                }
                k += 1;
            }
            return a;
        }
    };
*/


class Solution {
public:
    int minVal(int a, int b) {
        int setbitsA = 0, setbitsB = 0;
        int tempA = a, tempB = b;
        while (tempA) {
            int rsb = tempA & (-tempA);
            setbitsA++;
            tempA -= rsb;
        }
        while (tempB) {
            int rsb = tempB & (-tempB);
            setbitsB++;
            tempB -= rsb;
        }
        int x = 0;
        if (setbitsA >= setbitsB) {
            while (setbitsB) {
                int shift = floor(log2(a));
                x += (1 << shift);
                setbitsB--;
                a = (a ^ (1 << shift));
            }
        } else {
            x = a;
            setbitsB -= setbitsA;
            int curr = 0;
            while (setbitsB) {
                if ((a & 1) == 0) {
                    x += (1 << curr);
                    setbitsB--;
                }
                curr++;
                a >>= 1;
            }
        }
        return x;
    }
};



// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}  // } Driver Code Ends