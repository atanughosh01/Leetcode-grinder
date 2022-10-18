//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends



// Problem : https://practice.geeksforgeeks.org/problems/print-diagonally4331/1



class Solution {
public:
	vector<int> downwardDigonal(int n, vector<vector<int>> &arr) {
		vector<int> ans;
		for (int j = 0; j < n; j++) {
			for (int k = 0, t = j; k <= j, t >= 0; k++, t--) {
				ans.push_back(arr[k][t]);
			}
		}
		int j = n - 1;
		for (int i = 1; i < n; i++) {
			for (int k = i, t = j; k <= j, t >= i; k++, t--) {
				ans.push_back(arr[k][t]);
			}
		}
		return ans;
	}
};



//{ Driver Code Starts.



int main()
{

    
    int t;
    cin >> t;
    while(t--) 
    {
        int n;
        cin >> n;

        vector<vector<int>> A(n, vector<int>(n));

        for(int i = 0; i < n; i++)
        	for(int j = 0; j < n; j++)
        		cin >> A[i][j];

        Solution obj;
        vector<int> ans = obj.downwardDigonal(n, A);

        for(auto i:ans)
        	cout << i << " ";

	    cout << "\n";
    }

    return 0;
}

// } Driver Code Ends