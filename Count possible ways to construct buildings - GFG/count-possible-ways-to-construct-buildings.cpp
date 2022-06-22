// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



// Problem : https://practice.geeksforgeeks.org/problems/count-possible-ways-to-construct-buildings5007/1



const int M = 1e9 + 7;

class Solution{
public:
	int TotalWays(int n) {
	    if (!n) return 1;
	    if (n==1) return 4;
	    int a=1, b=2;
	    long long int ans = 0;
	    for(int i = 2; i <= n; i++) {
	        ans = (a+b) % M;
	        a = b;
	        b = ans;
	    }
	    return (ans*ans) % M;
	}
};



// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends