// { Driver Code Starts
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


 // } Driver Code Ends



// Problem : https://practice.geeksforgeeks.org/problems/transform-string5648/1



class Solution {
public:
    int transform (string A, string B) {
        int ans=0;
        unordered_map<char,int>mp;
        for (auto i : A) mp[i]++;
        for (auto i : B) mp[i]--;
        for (auto i : mp) {
            if (i.second != 0)
               return -1;
        }
        int i = A.size()-1, j = B.size()-1;
        while (i>=0 && j>=0) {
           if (A[i] == B[j]) i--,j--;
           else ans++,i--;
        }
        return ans;
    }
};



// { Driver Code Starts.

int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution ob;
        cout <<ob.transform (A, B) << endl;
    }
}  // } Driver Code Ends