// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



// Problem : https://practice.geeksforgeeks.org/problems/finding-profession3834/1



class Solution {
public:
    char profession(int level, int pos) {
        if (pos == 1) return 'e';
        char parent = profession(level-1, (pos+1)/2);
        if (pos % 2) return parent;
        return parent == 'e'? 'd':'e';
    }
};



// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int level, pos;
        cin>>level>>pos;
        
        Solution ob;
        if(ob.profession(level, pos) == 'd')
            cout<<"Doctor\n";
        else
            cout<<"Engineer\n";
    }
    return 0;
}  // } Driver Code Ends