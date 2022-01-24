// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Problem : https://practice.geeksforgeeks.org/problems/capacity-to-ship-packages-within-d-days/1


class Solution {
  public:
    int leastWeightCapacity(int a[], int N, int D) {
        auto check=[&](int x){
            int cnt=1,sum=0;
            for(int i=0;i<N;i++){
                if(sum+a[i]>x)cnt++,sum=a[i];
                else sum+=a[i];
            }
            return cnt<=D;
        };
        int l=1,r=0,ans;
        for(int i=0;i<N;i++)l=max(l,a[i]),r+=a[i];
        while(l<=r){
            int mid=(l+r)/2;
            if(check(mid)){
                r=mid-1;
                ans=mid;
            }
            else{
                l=mid+1;
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
        int N,D;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr,N,D) << endl;
    }
    return 0;
}  // } Driver Code Ends