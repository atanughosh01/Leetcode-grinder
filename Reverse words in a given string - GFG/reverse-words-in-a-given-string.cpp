// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


// Problem : https://practice.geeksforgeeks.org/problems/reverse-words-in-a-given-string5459/1


class Solution {
public:
    string reverseWords(string S) {
        stack<string> stk;
        S += '.';
        string word = "";
        for(int i=0; i<S.length(); i++) {
            if(S[i]!='.') word += S[i];
            else {
                stk.push(word);
                word = "";
            }
        }
        
        string res = "";
        while(!stk.empty()) {
            res += stk.top()+'.';
            stk.pop();
        }
        res.pop_back();
        return res;
    } 
};


// { Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}  // } Driver Code Ends