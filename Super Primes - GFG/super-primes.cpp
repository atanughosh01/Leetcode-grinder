// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



// Problem : https://practice.geeksforgeeks.org/problems/super-primes2443/1



class Solution {
private:
    bool isPrime(int n){
        if (n%2 == 0)
            return false;
        for (int i=3; i<=sqrt(n); i++){
            if (n%i == 0)
                return false;
        }
        return true;
    }
public:
	int superPrimes(int n) {
	    int count = 0;
        for (int i=5; i<=n; i++) {
            if (isPrime(i) && isPrime(i-2))
                count++;
        }
        return count;
	}
};



// { Driver Code Starts.

int main() 
{

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
   		Solution ob;
   		cout << ob.superPrimes(n) << "\n";
   	}

    return 0;
}
  // } Driver Code Ends