// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



// Problem : https://practice.geeksforgeeks.org/problems/killing-spree3020/1



class Solution {
public:
    long long int killinSpree(long long int n) {
        long long int i , sum , val, ans = 0;
        for(i = 1; sum <= n; i++) {
           val = i*i;
           sum += val;
          ans++;
       }
       return ans - 1;
    }
};



// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int n; cin>>n;
        Solution obj;
        long long int ans = obj.killinSpree(n);
        cout<<ans<<"\n";
    }
    return 0;
}
  // } Driver Code Ends