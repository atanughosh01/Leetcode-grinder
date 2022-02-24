// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends




// Problem : https://practice.geeksforgeeks.org/problems/return-two-prime-numbers2509/1



class Solution{
private:
    bool isprime(int n) {
        if(n==2||n==3||n==5)
            return true;
        if(n%2==0 || n%3==0 || n%5==0)
            return false;
        for(int i=5;i<=sqrt(n);i++) {
            if(n%i==0)
                return false;
        }
        return true;
    }
public:
    vector<int> primeDivision(int N){
        vector<int> result;
        for(int i=2; i<N; i++) {
            if(isprime(i) && isprime(N-i)) {
                 result.push_back(i);
                 result.push_back(N-i);
                 break;
             }
        }
    return result;
    }
};



// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.primeDivision(N);
        cout<<ans[0]<<" "<<ans[1]<<"\n";
    }
    return 0;
}  // } Driver Code Ends