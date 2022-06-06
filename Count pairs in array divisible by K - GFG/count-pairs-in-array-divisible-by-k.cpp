// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



// Problem : https://practice.geeksforgeeks.org/problems/count-pairs-in-array-divisible-by-k/1



class Solution {
public:
    long long countKdivPairs(int A[], int n, int K) {
        unordered_map<int, int> mp;
        long long ans = 0;
        for(int i=0; i<n; i++) { 
            int rem1 = A[i]%K;
            if (rem1) ans += mp[K-A[i]%K];
            else ans += mp[0];
            mp[rem1]++;
        }
        return ans;
    }
};



// { Driver Code Starts.

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		int k;
		cin >> k;

        Solution ob;
		cout << ob. countKdivPairs(a, n , k) << "\n";



	}


	return 0;
}
  // } Driver Code Ends