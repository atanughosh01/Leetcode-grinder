// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



// Problem : https://practice.geeksforgeeks.org/problems/equivalent-sub-arrays3731/1

// Solution : https://www.geeksforgeeks.org/count-subarrays-total-distinct-elements-original-array



/*
    class Solution {
    public:
        int countDistinctSubarray(int *arr, int n) {
            int cnt = 0;
            unordered_set<int> us;
            for (int i=0; i<n; i++) {
                us.insert(arr[i]);
            }
            int k = us.size();
            for (int i=0; i<n; i++) {
                us.clear();
                for (int j=i; j<n; j++) {
                    us.insert(arr[j]);
                    if (us.size() == k) {
                        cnt++;
                    }
                }
            }
            return cnt;
        }
    };
*/



/*
    class Solution {
    public:
        int countDistinctSubarray(int *arr, int n) {
            int cnt = 0;
            unordered_set<int> us;
            for (int i=0; i<n; i++) {
                us.insert(arr[i]);
            }
            int k = us.size();
            for (int i=0; i<n; i++) {
                us.clear();
                for (int j=i; j<n; j++) {
                    us.insert(arr[j]);
                    if (us.size() == k) {
                        cnt += (n-j);
                        break;
                    }
                }
            }
            return cnt;
        }
    };
*/



// TC : O(n), SC : O(n), n = size of arr
class Solution {
public:
    int countDistinctSubarray(int *arr, int n) {
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[arr[i]]++;
        }
        auto k = mp.size();
        mp.clear();
        int cnt = 0, i = 0, j = 0;
        for (i = 0; i < n; i++) {
            mp[arr[i]]++;
            while (j <= i && k == mp.size()) {
                cnt += (n-i);
                mp[arr[j]]--;
                if (mp[arr[j]] == 0) {
                    mp.erase(arr[j]);
                }
                j++;
            }
        }
        return cnt;
    }
};



// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;	
		cout<<ob.countDistinctSubarray(a,n)<<endl;
	}
	return 0;
}  // } Driver Code Ends