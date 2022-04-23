// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



// Problem : https://practice.geeksforgeeks.org/problems/product-of-primes5328/1



class Solution{
private:
    const int mod = ((int)(1e9+7));
    long long checkPrime(long long num){
       for(int j = 2; j<=sqrt(num); j++) {
           if(num % j == 0){
               return 1;
           }
       }
       return num;
   }
public:
   long long primeProduct(long long L, long long R){
       long long pro = 1, i = L;
       while(i <= R){
           pro = (pro%mod * checkPrime(i)%mod)%mod;
           i++;
       }
       return pro;
   }
};



// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long L, R;
        cin>>L>>R;
        
        Solution ob;
        cout<<ob.primeProduct(L, R)<<"\n";
    }
    return 0;
}  // } Driver Code Ends