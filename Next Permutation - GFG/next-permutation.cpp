// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


// Problem : https://practice.geeksforgeeks.org/problems/next-permutation5226/1


class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> arr){
        int i=N-1;
        for(;i>=0;i--){
            if(i==0){
                sort(arr.begin(), arr.end());
                return arr;
            }
            if(arr[i]>arr[i-1])
                break;
        }
        i--;
        for(int j=N-1;j>i;j--){
            if(arr[i]<arr[j]){
                int temp = arr[i];
                arr[i]=arr[j];
                arr[j] = temp;
                break;
            }
        }
        sort(arr.begin()+i+1, arr.end());
        return arr;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends