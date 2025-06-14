// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int* greaterElement(int arr[], int n);

int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        int *b;
        b = greaterElement(arr, n);
        for(int i=0;i<n;i++){
            if(b[i] == -10000000)
                cout << "_ ";
            else
                cout << b[i] << " ";
        }
        cout<<endl;   
        
    }
    return 0;
}
// } Driver Code Ends



// Problem : https://practice.geeksforgeeks.org/problems/smallest-greater-elements-in-whole-array2751/1



int* greaterElement(int a[], int n) {
    set<int> s;
    for(int i = 0; i < n; i++) {
       s.insert(a[i]);
    }
   for(int i = 0; i < n; i++) {
        auto it = s.find(a[i]);
        auto temp = ++it;
        if(temp != s.end()) {
            a[i] = *temp;
        } else{
            a[i] = -10000000;
        }
    }
    return a;
}
