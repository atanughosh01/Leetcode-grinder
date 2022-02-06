// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


// Problem : https://practice.geeksforgeeks.org/problems/minimum-swaps/1


class Solution {
public:

/*
	//	Quadratic Time Complexity
	int minSwaps(vector<int>& nums) {
		vector<pair<int, int>> v;
		int n = nums.size();
		for (int i = 0; i < n; i++)
			v.emplace_back(nums[i], i);
		sort(v.begin(), v.end());
		int swaps = 0;
		for (int i = 0; i < n; i++) {
			int j = v[i].second;
			while (i != j) {
				swap(v[i], v[j]);
				j = v[i].second;
				swaps++;
			}
		}
		return swaps;
	}
*/

	//	Linear Time Complexity
	int minSwaps(vector<int>& nums) {
		vector<pair<int, int>> v;
		int n = (int)nums.size();
		for (int i = 0; i < n; i++)
			v.emplace_back(nums[i], i);
		sort(v.begin(), v.end());
		int swaps = 0;
		for (int i = 0; i < n;) {
			if (v[i].second != i) {
				swaps++;
				swap(v[i], v[v[i].second]);
			}
			else
				i++;
		}
		return swaps;
	}
};


// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends