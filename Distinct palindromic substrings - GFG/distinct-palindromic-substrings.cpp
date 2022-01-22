// { Driver Code Starts
// C++ program to find all distinct palindrome sub-strings
// of a given string
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Problem : https://practice.geeksforgeeks.org/problems/distinct-palindromic-substrings5141/1


class Solution{
  public:
    bool isPalindrome(string str) {
        int i=0, j=str.size()-1;
        while(i<j){
            if(str[i]!=str[j])
                return false;
            i++, j--;
        }
        return true;
    }

    int palindromeSubStrs(string s) {
        int n = s.size();
        unordered_map<string, int> mp; 
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(s[i]!=s[j]){
                    continue;
                } else {
                    string temp = s.substr(i, j-i+1);
                    if(isPalindrome(temp)){
                        mp[temp]++;
                    }
                }
            }
        }
        return mp.size();
    }
};


// { Driver Code Starts.

// Driver program
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.palindromeSubStrs(str) << endl;
    }
    return 0;
}
  // } Driver Code Ends