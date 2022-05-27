// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



// Problem : https://practice.geeksforgeeks.org/problems/fraction-trouble1410/1



class Solution {
public:
    vector<int> numAndDen(int n, int d) {
        double val = (double)n/d, mx = -1;
        vector<int> ans;
        for(int i = n+1; i <= 10000; i++) {
            int j = (i*d)/n + 1;
            if (j > 10000) break;
            double v = (double)i/j;
            if(v < val && v > mx) {
                mx = v;
                ans = {i, j};
            }
        }
        return ans;
    }
};



// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,d;
        cin >> n >> d;
        Solution ob;
        vector<int>ans=ob.numAndDen(n,d);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
  // } Driver Code Ends