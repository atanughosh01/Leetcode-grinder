// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


vector<int> Smallestonleft(int arr[], int n);


int main() {
	
	int t;
	
	cin >> t;
	
	while(t--){
	    
	    int n;
	    cin >> n;
	    int arr[n+1];
	    
	    for(int i=0;i<n;i++){
	        cin>> arr[i];
	    }
	    
	    vector<int> b;
	    b = Smallestonleft(arr, n);
	    for(int i=0;i<n;i++)
	        cout << b[i] << " ";
	       
	    cout << endl;
	    
	    
	}
	
	return 0;
}// } Driver Code Ends



// Problem : https://practice.geeksforgeeks.org/problems/smaller-on-left20360700/1



vector<int> Smallestonleft(int arr[], int n) {
   set<int> st;
   vector<int> ans(n,-1);
   for(int i=0; i<n; i++) {
       st.insert(arr[i]);
       auto it = st.find(arr[i]);
       if(it != st.begin()) {
           ans[i] = *(--it);
       }
   }
   return ans;
}
