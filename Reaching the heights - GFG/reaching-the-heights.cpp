// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


vector<int> reaching_height(int n, int a[]) ;

int main() {
	int t;
	cin >> t;
	while (t-- > 0) {
	    int n; 
	    cin >> n;
	    int a[n];
	    for (int i = 0; i < n; i++) 
	        cin >> a[i];
	    vector<int> v;
	    v = reaching_height(n,a);
	
	    if(v.size()==1 and v[0] == -1){
	        cout << "Not Possible\n";
	    }
	    else{
	    for(int i:v)
	        cout << i << " ";
	    cout << endl;}
	    
	}
	return 0;
}// } Driver Code Ends



// Problem : https://practice.geeksforgeeks.org/problems/reaching-the-heights1921/1



vector<int> reaching_height(int n, int *a) {
    vector<int> ans(n);
    sort(a, a+n);
    int i = 0, j = n-1, k = 0, t = 0;
    for (; k < n; k++) {
        if (k % 2 == 0) {
            ans[k] = a[j--];
            t += ans[k];
        } else {
            ans[k] = a[i++];
            t -= ans[k];
        }
    }
    if (t > 0) return ans;
    return {-1};
}
