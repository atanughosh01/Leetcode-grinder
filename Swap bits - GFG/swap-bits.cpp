// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



// Problem : https://practice.geeksforgeeks.org/problems/swap-bits5726/1



class Solution{
public:    
    int swapBits(int x, int p1, int p2, int n) {
        vector<int>v(32);
        int ans=0, j=0, p= 0, n1 = p1 + n, n2 = p2 + n;
        while(x) {
            int bit = x&1;
            x >>= 1ll;
            v[j++] = bit;
        }
        while(p1<n1 && p2<n2) {
           swap(v[p1++], v[p2++]);
        }
        for(int i=0; i<32; i++) {
            if(v[i]==1) 
                ans += pow(2,p);
           p++;
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
		int x,p1,p2,n;
		cin>>x>>p1>>p2>>n;
		Solution obj;
		int res=obj.swapBits(x,p1,p2,n);
		printf("%d\n", res);
	}
    return 0;
}  // } Driver Code Ends