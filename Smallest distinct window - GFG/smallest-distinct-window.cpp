// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



// Problem : https://practice.geeksforgeeks.org/problems/smallest-distant-window3132/1



class Solution {
   public:
    int findSubString(string s) {
        unordered_map<char, int> mp;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (mp.find(s[i]) == mp.end()) {
                mp[s[i]] = 0;
            }
        }
        int i = 0, j = 0, count = 0, min_dis = INT_MAX;
        while (j < n) {
            if (j < n and count != mp.size()) {
                mp[s[j]]++;
                if (mp[s[j]] == 1) count++;
                j++;
            } else if (count == mp.size()) {
                while (i < j && count == mp.size()) {
                    mp[s[i]]--;
                    if (mp[s[i]] == 0) {
                        count--;
                        min_dis = min(min_dis, j - i);
                    }
                    i++;
                }
            }
        }
        while (i < j && count == mp.size()) {
            mp[s[i]]--;
            if (mp[s[i]] == 0) {
                count--;
                min_dis = min(min_dis, j - i);
            }
            i++;
        }
        return min_dis;
    }
};




// { Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}  // } Driver Code Ends