// { Driver Code Starts
// CPP program to find maximum sum
// by selecting a element from n arrays
#include<bits/stdc++.h>

using namespace std;

// To calculate maximum sum by
// selecting element from each array
int maximumSum( int n,int m, vector<vector<int>> &a);



// Driver program to test maximumSum
int main() {
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        vector<vector<int>> arr(n, vector<int>(m,0));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            cin>>arr[i][j];
            
        cout << maximumSum(n,m,arr)<<endl;
    
    }
    return 0;

}
// } Driver Code Ends



// Problem : https://practice.geeksforgeeks.org/problems/maximum-sum-of-increasing-order-elements-from-n-arrays4848/1

/*
int maximumSum(int n, int m, vector<vector<int>> &a) {

    for (auto& v : a) {
        sort(v.begin(), v.end());
    }

    int x = a[n - 1][m - 1];
    int sum = x;

    for (int i = n - 2; i >= 0; i--) {
        if (a[i][0] >= a[i + 1][m - 1]) {
            return 0;
        }
        for (int j = m - 1; j >= 0; j--) {
            if (a[i][j] < x) {
                x = a[i][j];
                sum += x;
                break;
            } else if (j == 0) {
                return 0;
            }
        }
    }
    return sum;
}
*/

int maximumSum( int n,int m, vector<vector<int>> &a) {
    
    int prev = *max_element(&a[n-1][0],	&a[n-1][m-1] + 1);
    int sum = prev;

    for (int i = n - 2; i >= 0; i--) {
        int max_smaller = INT_MIN;
        for (int j = m - 1; j >= 0; j--) {
            if (a[i][j] < prev && a[i][j] > max_smaller)
                max_smaller = a[i][j];
        }

        if (max_smaller == INT_MIN)
            return 0;

        prev = max_smaller;
        sum += max_smaller;
    }
    return sum;
}