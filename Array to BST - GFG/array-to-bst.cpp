// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



// Problem : https://practice.geeksforgeeks.org/problems/array-to-bst4443/1



class Solution {
private:
    void solve(int l, int h, vector<int> &v, vector<int> &nums) {
        if (l > h) return;
        int mid = (l + h) / 2;
        v.push_back(nums[mid]);
        solve(l, mid - 1, v, nums);
        solve(mid + 1, h, v, nums);
    }
public:
    vector<int> sortedArrayToBST(vector<int> &nums) {
        vector<int> v;
        int n = nums.size();
        int mid = (n - 1) / 2;
        v.push_back(nums[mid]);
        solve(0, mid - 1, v, nums);
        solve(mid + 1, n - 1, v, nums);
        return v;
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
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int>ans = obj.sortedArrayToBST(nums);
		for(auto i: ans)
			cout << i <<" ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends