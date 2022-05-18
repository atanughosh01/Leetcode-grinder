// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



// Problem : https://practice.geeksforgeeks.org/problems/permutation-with-spaces3627/1



class Solution {
private:
    void fun(int i, string curr, vector<string> &ans, string &s){
        if (i == s.size()-1){
           curr += s[i];
           ans.push_back(curr);
           return;
        }
        curr += s[i];
        fun(i+1, curr, ans, s);
        if (i == s.size()-1) return;
        curr += ' ';
        fun(i+1, curr, ans, s);
   }
public:
    vector<string> permutation(string s) {
        string curr = "";
        vector<string> ans;
        fun(0, curr, ans, s);
        sort(ans.begin(), ans.end());
        return ans;
    }
};



// { Driver Code Starts.

int  main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        vector<string> ans;
        Solution obj;
        ans = obj.permutation(S);
        for(int i=0;i<ans.size();i++){
            cout<<"("<<ans[i]<<")";
        }
        cout << endl;
    }
}
  // } Driver Code Ends