// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



// Problem : https://practice.geeksforgeeks.org/problems/min-sum-formed-by-digits3551/1



class Solution{
public:
    long long minSum(int *arr, int n) {
        sort(arr, arr+n);
        long long a = 0, b = 0;
        for(int i = 0; i < n; i += 2) {
            a = a * 10 + arr[i];
        }
        for (int i = 1; i < n; i += 2) {
            b = b * 10 + arr[i];
        }
        return a + b;
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
        int arr[n+1];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.minSum(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends