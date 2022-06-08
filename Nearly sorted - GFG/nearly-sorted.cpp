// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



// Problem : https://practice.geeksforgeeks.org/problems/nearly-sorted-1587115620/1



class Solution {
public:
    vector<int> nearlySorted(int arr[], int n, int k) {
        vector<int> ans(n);
        set<int> st;
        for (int j=0; j<k; j++) st.insert(arr[j]);
        for (int i=0; i<n; i++) {
            if (i+k < n) st.insert(arr[i+k]);
            ans[i] = *st.begin();
            st.erase(*st.begin());
        }
        return ans;
    }
};



// { Driver Code Starts.

int main()
 {
	int T;
	cin>> T;
	
	while (T--)
	{
	    int num, K;
	    cin>>num>>K;
	    
	    int arr[num];
	    for(int i = 0; i<num; ++i){
	        cin>>arr[i];
	    }
	    Solution ob;
	    vector <int> res = ob.nearlySorted(arr, num, K);
	    for (int i = 0; i < res.size (); i++)
	        cout << res[i] << " ";
	        
	    cout<<endl;
	}
	
	return 0;
}
  // } Driver Code Ends