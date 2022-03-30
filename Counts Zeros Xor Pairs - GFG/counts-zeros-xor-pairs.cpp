// { Driver Code Starts
// C++ program to find number 
// of pairs in an array such
// that their XOR is 0
#include <bits/stdc++.h>
using namespace std;

// Function to calculate the
// count
long long int calculate(int a[], int n);

// Driver Code
int main()
{

	int t;
	cin>>t;
	while(t--)
	{
	  int n;
	  cin>>n;
	  int arr[n+1];
	  for( int i=0;i<n;i++)
	        cin>>arr[i];
	    cout << calculate(arr, n)<<endl;
        
	}
	return 0;
}

// } Driver Code Ends



// Problem : https://practice.geeksforgeeks.org/problems/counts-zeros-xor-pairs0349/1


/*
    long long int calculate(int arr[], int n) {
        long long count = 0;
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                if (arr[i] == arr[j])
                    count++;
            }
        }
        return count;
    }
*/

long long calculate(int a[], int n) {
    unordered_map<int,int> mp;
    for(int i=0; i<n; i++) mp[a[i]]++;
    long long ans = 0;
    for(auto it : mp) {
        long long cnt = it.second;
        ans += ((cnt)*(cnt-1))/2;
    }
    return ans;
}
