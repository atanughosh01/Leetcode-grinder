// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends


// Problem : https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1


class Solution{
public:
    int *findTwoElement(int *arr, int n) {
       int r=0;
       for(int i=0;i<n;i++)
       r=(r^arr[i])^(i+1);
       int sb=r&(~(r-1));
       int fst=0,snd=0;
       for(int i=0;i<n;i++) {
           if((arr[i]&sb)!=0)
           fst=fst^arr[i];
           else
           snd=snd^arr[i];
           if(((i+1)&sb)!=0)
           fst=fst^(i+1);
           else
           snd=snd^(i+1);
       }
       bool flag=false;
       for(int i=0;i<n;i++) {
           if(arr[i]==fst) {
               flag=true;
               break;
           }
       }
       int ar[2];
       if(flag) {
           ar[0]=fst;
           ar[1]=snd;
       }
       else {
           ar[0]=snd;
           ar[1]=fst;
       }
       int *p=ar;
       return p;
    }
};



// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends