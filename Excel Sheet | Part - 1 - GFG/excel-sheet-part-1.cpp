// { Driver Code Starts
//Initial template for C++


#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


// Problem : https://practice.geeksforgeeks.org/problems/excel-sheet5448/1


class Solution{
public:
    string ExcelColumn(int N) {
        string ans = "";
        while(N) {
           if(N % 26 == 0) {
               ans += 'Z';
               N--;
           }
           else
               ans += ('A' + (N % 26) - 1);
           N /= 26;
       }
       reverse(ans.begin(), ans.end());
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
        int n;
        cin>>n;
        Solution ob;
        cout<<ob.ExcelColumn(n)<<endl;
    }
    return 0;
}
      // } Driver Code Ends