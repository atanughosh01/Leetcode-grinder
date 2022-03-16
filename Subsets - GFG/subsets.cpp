// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



// Problem : https://practice.geeksforgeeks.org/problems/subsets-1613027340/1



class Solution {
private:
    vector<vector<int>> res;
    vector<int> curr;
    void generate(vector<int>& arr, int i, int n) {
        if(i >= n) {
            res.push_back(curr);
            return;
        }
        curr.push_back(arr[i]);
        generate(arr, i + 1, n);
        curr.pop_back();
        generate(arr, i + 1, n);
    }
public:
    vector<vector<int>> subsets(vector<int>& arr) {
        int n = arr.size();
        generate(arr, 0, n);
        sort(res.begin(), res.end());
        return res;
    }
};




// { Driver Code Starts.

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n, x;
		cin >> n;

		vector<int> array;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			array.push_back(x);
		}
        
        
        Solution ob;
		vector<vector<int> > res = ob.subsets(array);

		// Print result
		for (int i = 0; i < res.size(); i++) {
			for (int j = 0; j < res[i].size(); j++)
				cout << res[i][j] << " ";
			cout << endl;
		}

		
	}

	return 0;
}  // } Driver Code Ends