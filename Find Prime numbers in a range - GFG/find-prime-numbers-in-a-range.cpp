// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


// Problem : https://practice.geeksforgeeks.org/problems/find-prime-numbers-in-a-range4718/1


class Solution {
private:
    void seive(int N, vector<bool>& isPrime){
      isPrime[0]=false;
      isPrime[1]=false;
      for(int i=2;i*i<=(N+1);i++){
          if(isPrime[i]){
              for(int j=i*i;j<=N;j+=i){
                  isPrime[j]=false;
              }
          }
      }
      
  }

public:
    vector<int> primeRange(int M, int N) {
        vector <bool> isPrime(N+1,true);
        seive(N,isPrime);
        vector <int> ans;
        for(int i=M; i<=N; i++){
            if(isPrime[i])
                ans.emplace_back(i);
        }
        return ans;
    }
};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, K;
        cin >> M >> N;
        Solution ob;
        vector<int> ans = ob.primeRange(M, N);
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
}  // } Driver Code Ends