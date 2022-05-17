// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



// Problem : https://practice.geeksforgeeks.org/problems/minimum-number-in-a-sorted-rotated-array-1587115620/1



class Solution {
public:
    int minNumber(int arr[], int low, int high) {
        int last = arr[high];
        while (low < high) {
            int mid = low + ((high - low) >> 1);
            if (arr[mid] > last) low = mid + 1;
            else high = mid;
        }
        return arr[low];
    }
};



// { Driver Code Starts.


int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];	
		Solution obj;
		cout << obj.minNumber(a,0,n-1) << endl;
	}
	return 0;
}  // } Driver Code Ends