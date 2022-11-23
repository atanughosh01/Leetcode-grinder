//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends



// Problem : https://practice.geeksforgeeks.org/problems/maximum-sum-lcm3025/1



class Solution {
public:
	long long maxSumLCM(int n) {
		long long sum = 0, m = n;
		for (long long i = 1; i * i <= m; ++i) {
			if (m % i == 0) {
				sum += i;
				long rem = m / i;
				if (rem != i) {
					sum += rem;
				}
			}
		}
		return sum;
	}
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n;
        cin >> n ;
        Solution ob;
        cout<<ob.maxSumLCM(n)<<endl;
    }
    return 0;
}

// } Driver Code Ends