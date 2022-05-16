// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends



// Problem : https://practice.geeksforgeeks.org/problems/longest-subarray-with-sum-divisible-by-k1259/1



class Solution {
   public:
    int longSubarrWthSumDivByK(int arr[], int n, int k) {
        int ans = 0, sum = 0, rem = 0;
        unordered_map<int, int> umap;
        umap.insert({0, -1});
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            rem = sum % k;
            if (rem < 0) rem += k;
            if (umap.find(rem) != umap.end()) {
                auto idx = umap.find(rem);
                int len = i - (idx->second);
                ans = max(ans, len);
            } else {
                umap.insert({rem, i});
            }
        }
        return ans;
    }
};



// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}
  // } Driver Code Ends