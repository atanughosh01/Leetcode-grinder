// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



// Problem : https://practice.geeksforgeeks.org/problems/2ac2f925b836b0625d848a0539ffd3d2d2995f92/1



class Solution {
public:
    long long countStrings(string s) {
        unordered_map<int,int> hmp;
        for(auto ch:s){
            hmp[ch-'a']++;
        }
        int N = s.size();
        long long ans = 0;
        bool flag = false;
        for(int i=0; i<N; i++){
            char ch = s[i];
            for(int j=0; j<26 ; j++){
                if(ch-'a' == j){
                    if(hmp[j] > 1){
                        flag = true;
                    }
                    continue;
                } else{
                    ans += hmp[j];
                }
            }
            hmp[ch-'a']--;
        }
        return flag? ans+1: ans;
    }
};



// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution ob;
        long long ans = ob.countStrings(S);
        cout<<ans<<endl;
    }
    return 0;
}   // } Driver Code Ends