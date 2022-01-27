// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

 // } Driver Code Ends


// Problem : https://practice.geeksforgeeks.org/problems/handshakes1303/1


class Solution{
public:
    int count(int N){
        if(N==0){
           return 1;
        }
        int ans=0;
        for(int i=0;i<N;i=i+2){
            ans+=count(i)*count(N-2-i);
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
        int N;
        cin>>N;
        Solution ob;
        cout << ob.count(N) << endl;
    }
    return 0; 
}  // } Driver Code Ends