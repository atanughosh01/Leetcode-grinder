// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends



// Problem : https://practice.geeksforgeeks.org/problems/d35adfbe367861ec1e67bea6e0efebe0a0ee3550/1



class Solution{   
public:
    string moveRobots(string s1, string s2){
        int l1=0;
      int l2=0;
      int n=s1.size();
      while(l1<n && l2<n){
            while(l1<n && s1[l1]=='#')
               l1++;
            while(l2<n && s2[l2]=='#')
               l2++;
            if(s1[l1]!=s2[l2])
               return "No";
            else{
                if(s1[l1]=='A'){
                    if(l1>=l2)
                       l1++,l2++;
                    else
                      return "No";
                }
                else{
                     if(l1<=l2)
                       l1++,l2++;
                     else
                       return "No";
                    
                }
            }
      }
      return "Yes";
    }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s1,s2;
        cin >> s1;
        cin >> s2;
        
        Solution ob;
        cout << ob.moveRobots(s1, s2) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends