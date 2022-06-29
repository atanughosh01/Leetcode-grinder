// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
// #include <algorithm>


 // } Driver Code Ends



// Problem : https://practice.geeksforgeeks.org/problems/wave-array-1587115621/0/



class Solution {
public:
    void convertToWave(int n, vector<int> &a) {
        for(int i = 1; i < n; i += 2) {
           swap(a[i], a[i - 1]);
        }
    }
};



// { Driver Code Starts.

int main()
{
    int t,n;
    cin>>t; //Input testcases
    while(t--) //While testcases exist
    {
        cin>>n; //input size of array
        vector<int> a(n); //declare vector of size n
        for(int i=0;i<n;i++)
            cin>>a[i]; //input elements of array
        Solution ob;
        ob.convertToWave(n, a);

        for(int i=0;i<n;i++)
            cout<<a[i]<<" "; //print array
            
        cout<<endl;
    }
}  // } Driver Code Ends