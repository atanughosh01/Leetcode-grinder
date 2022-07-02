// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



// Problem : https://practice.geeksforgeeks.org/problems/word-break-part-23249/1



class Solution {
    unordered_map<string, int> mp;
    vector<string> ans;
private:
    void solve(string r, string k) {
        string p;
        for (int i = 1; i <= r.size(); i++) {
            p = r.substr(0, i);
            if (mp[p] && i == r.size()) {
                ans.push_back(k + p);
            } else if (mp[p] == 1) {
                solve(r.substr(i), k + p + " ");
            }
        }
    }
public:
    vector<string> wordBreak(int n, vector<string> &dict, string s) {
        for (string &s : dict) mp[s] = 1;
        solve(s, "");
        return ans;
    }
};



// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends