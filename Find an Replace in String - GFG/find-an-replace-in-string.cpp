// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



// Problem : https://practice.geeksforgeeks.org/problems/find-an-replace-in-string/1



class Solution {
public:
    string findAndReplace(string S ,int Q, int index[], string sources[], string targets[]) {
        string res = "";
        int curr = 0;
        for (int i=0; i<Q && curr < S.length(); i++){
            while(curr < index[i])
                res += S[curr++];
            int idx = index[i], len = sources[i].length();
            if (S.substr(idx, len) == sources[i]) {
                res += targets[i];
                curr += len;
            }
        }
        while(curr < S.length())
            res += S[curr++];
        return res;
    }
};



// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        
        int Q;
        cin>>Q;
        int index[Q];
        string sources[Q], targets[Q];
        
        for(int i=0; i<Q; i++)
            cin>>index[i];
        for(int i=0; i<Q; i++)
            cin>>sources[i];
        for(int i=0; i<Q; i++)
            cin>>targets[i];

        Solution ob;
        cout<<ob.findAndReplace(S,Q,index,sources,targets)<<endl;
    }
    return 0;
}  // } Driver Code Ends