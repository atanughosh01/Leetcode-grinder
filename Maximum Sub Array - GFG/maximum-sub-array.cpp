//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends



// Problem : https://practice.geeksforgeeks.org/problems/maximum-sub-array5443/1



class Solution {
public:
	vector<int> findSubarray(int *a, int n) {
		int i, j, s, e;
		long long cs, ms;
		s = e = i = j = cs = ms = 0;
		while (j < n) {
			if (a[j] >= 0) {
				cs += a[j];
				if (cs >= ms) {
					s = i;
					e = j;
					ms = cs;
				}
			} else {
				cs = 0;
				i = j + 1;
			}
			j++;
		}
		if (s == e && a[s] < 0) return { -1};
		vector<int> v;
		for (int i = s; i <= e; i++) {
			v.push_back(a[i]);
		}
		return v;
	}
};



//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findSubarray(a, n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends