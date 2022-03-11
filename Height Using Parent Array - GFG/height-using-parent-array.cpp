// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



// Problem : https://practice.geeksforgeeks.org/problems/height-using-parent-array4103/1



class Solution{
public:
    int findHeight(int N, int arr[]){
        int ans = 0;
        arr[0] = 1;
        if(N >= 2){
            ans = 1;
        }
        for(int i=1; i<N; i++){
            arr[i] = arr[arr[i]]+1;
            ans = max(ans, arr[i]);
        }
        return ans;
    }
};



// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.findHeight(N, arr)<<"\n";
    }
    return 0;
}  // } Driver Code Ends