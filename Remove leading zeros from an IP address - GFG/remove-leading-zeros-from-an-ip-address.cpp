// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Problem : https://practice.geeksforgeeks.org/problems/remove-leading-zeros-from-an-ip-address3530/1


class Solution {
public:
    string newIPAdd (string s) {
         string ans="",k="";
        for(char i:s){
            if(i=='.'){
                if(k.empty())
                    k='0';
                ans+=k+'.';
                k="";
            } else {
                if(k.empty() and i=='0')
                    continue;
                else k+=i;
            }
        }
        if(k.empty())
            k='0';
        return ans+k;
    }
};


// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.newIPAdd (s) << endl;
    }
}

  // } Driver Code Ends