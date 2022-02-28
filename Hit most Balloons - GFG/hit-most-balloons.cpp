// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



// Problem : https://practice.geeksforgeeks.org/problems/4e75764f8f1638eb4f1c5478ca1986043e15e39a/1



class Solution {
 public:
    int mostBalloons(int N, pair<int, int> arr[]) {
        int ans = INT_MIN;
        for(int i = 0; i < N; i++){
            unordered_map<double, int>mp;
            int dups = 1, t_ans = INT_MIN;
            int infs = 0;
            for(int j = i + 1; j < N; j++) {
                int dx = arr[i].first - arr[j].first;
                int dy = arr[i].second - arr[j].second;
                if(dx == 0 && dy == 0) {
                    dups++;
                }
                else if(dx == 0) {
                    infs++;
                    t_ans = max(t_ans, infs);
                }
                else{
                    mp[dy/double(dx)]++;
                    t_ans = max(t_ans, mp[dy/double(dx)]);
                }
            }
            ans = max(ans, t_ans + dups);
        }
        return ans;
    }
};



// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        pair<int, int> arr[N];
        for (int i = 0; i < N; i++) {
            cin >> arr[i].first;
        }
        for (int i = 0; i < N; i++) {
            cin >> arr[i].second;
        }
        Solution ob;
        cout << ob.mostBalloons(N, arr) << endl;
    }
}  // } Driver Code Ends