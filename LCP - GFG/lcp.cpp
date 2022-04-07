// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



// Problem : https://practice.geeksforgeeks.org/problems/cf0cd86c66d07222499f84ec22dbcf6cae30e848/1



class Solution{
public:
    string LCP(string arr[], int n) {
        int minsize = INT_MAX;
        for(int i=0; i<n; i++) {
            int s = arr[i].size();
            minsize = min(minsize,s);
        }
        int ans=0;
        for(int j=0; j<minsize; j++) {
            bool f=false;
            for(int i=0; i<n-1; i++) {
                if (arr[i][j] != arr[i+1][j]) {
                    f= true;
                    break;
                }
            }
            if(f) break;
            ans++;
        }
        return ans==0 ? "-1": arr[0].substr(0,ans);
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
	        string arr[n];
	        for(int i = 0;i<n;i++)
	            cin>>arr[i];
	        Solution ob;
	        cout<<ob.LCP(arr,n)<<endl;
	    }
	return 0;
}  // } Driver Code Ends