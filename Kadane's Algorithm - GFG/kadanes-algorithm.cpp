// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
     long long maxSubarraySum(int arr[], int n){
       
       // Your code here
       long long sum=0;
       int maxi = *max_element(arr, arr+n);
       for(int i=0;i<n;i++){
           for(int j=n;j>i;j--){
               sum=accumulate(arr+i, arr+j,0);
               if(sum>maxi){
                   maxi=sum;
               }
           }
       }
       return maxi;
   }
};


// { Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}
  // } Driver Code Ends