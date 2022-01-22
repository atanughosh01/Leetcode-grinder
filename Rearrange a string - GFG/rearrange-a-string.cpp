// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


// Problem : https://practice.geeksforgeeks.org/problems/rearrange-a-string4100/1


class Solution {
  public:
    string arrangeString(string str) {
       int n = (int)str.size();
       int sum = 0;
       string s = "";
       for(int i=0; i<n; i++) {
           if(str[i]-'0'>=0 and str[i]-'0' <= 9)
                sum += str[i]-'0';
            else
                s += str[i];
       }
       sort(s.begin(), s.end());
       if(sum) s += to_string(sum);
       return s;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout <<ob.arrangeString(s) << endl;
    }
return 0;
}

  // } Driver Code Ends