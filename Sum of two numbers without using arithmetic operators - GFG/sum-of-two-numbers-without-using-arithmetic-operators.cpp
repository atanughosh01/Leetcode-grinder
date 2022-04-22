// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends



// Problem : https://practice.geeksforgeeks.org/problems/sum-of-two-numbers-without-using-arithmetic-operators/1



class Solution {
public:
    int sum(int a, int b) {
        return a+b;
    }
};



// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a,b;
        cin >> a>>b;
        
        Solution ob;
        cout<< ob.sum(a,b) <<"\n";
        
    }
    return 0;
}
  // } Driver Code Ends