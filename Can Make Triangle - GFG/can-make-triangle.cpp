// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends



// Problem : https://practice.geeksforgeeks.org/problems/51b7f8fb8b33d657a857f230361b7dad6565ce62/1



class Solution{
public:
    vector<int> canMakeTriangle(vector<int> p, int N){
        vector<int> l;
        for (int i = 0; i < N-2; i++) {
            if ((p[i] + p[i + 1] > p[i + 2]) && (p[i] + p[i + 2] > p[i + 1]) && (p[i+1] + p[i + 2] > p[i])) {
                l.push_back(1);
            }
            else {
                l.push_back(0);
            }
        }
        return l;
    }
}; 


// { Driver Code Starts.
int main() 
{ 
    int t;cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        vector<int> A(N);
        for(int i=0;i<N;i++)
            cin>>A[i];
        Solution ob;
        auto ans = ob.canMakeTriangle(A, N);
        for(int i=0;i<ans.size();i++)
            cout << ans[i] << " ";
        cout << endl;
        
    }

    return 0; 
}   // } Driver Code Ends