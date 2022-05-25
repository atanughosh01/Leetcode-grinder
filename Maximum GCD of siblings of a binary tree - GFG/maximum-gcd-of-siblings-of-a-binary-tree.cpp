// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



// Problem : https://practice.geeksforgeeks.org/problems/maximum-gcd-of-siblings-of-a-binary-tree/1


/*
    // 1:- C++ solution having time complexity as O(E*log(E)) and space complexity as O(1) is as follows :-
    
    class Solution {
       public:
        int maxBinTreeGCD(vector<vector<int>> &arr, int N) {
            if (N <= 2) return (0);
            sort(arr.begin(), arr.end());
            int ans = 0;
            for (int i = 0; i < arr.size() - 1; i++) {
                if (arr[i][0] == arr[i + 1][0]) {
                    int gcd = __gcd(arr[i][1], arr[i + 1][1]);
                    ans = max(ans, gcd);
                }
            }
            return ans;
        }
    };
*/


// 2 :- C++ solution having time complexity as O(E) and space complexity as O(N+E) as follows :-

class Solution {
private:
    int find_max(vector<vector<int>> &arr) {
        int mx = 0;
        for (int i = 0; i < arr.size(); i++) {
            mx = max(mx, arr[i][0]);
        }
        return mx;
    }
public:
    int maxBinTreeGCD(vector<vector<int>> &arr, int N) {
        if (N <= 2) return 0;
        vector<int> mp[find_max(arr) + 1], num;
        for (int i = 0; i < arr.size(); i++) {
            mp[arr[i][0]].push_back(arr[i][1]);
            num.push_back(arr[i][0]);
        }
        int ans = 0;
        for (int i = 0; i < num.size(); i++) {
            int n = num[i];
            if (mp[n].size() == 2) {
                ans = max(ans, __gcd(mp[n][0], mp[n][1]));
            }
        }
        return ans;
    }
};



// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,u,v;
        cin>>N;
        
        vector<vector<int>> arr;
        
        for(int i=0; i<N-1; i++)
        {
            cin>>u>>v;
            vector<int> edge;
            edge.push_back(u);
            edge.push_back(v);
            arr.push_back(edge);
        }

        Solution ob;
        cout << ob.maxBinTreeGCD(arr,N) << endl;
    }
    return 0;
}  // } Driver Code Ends