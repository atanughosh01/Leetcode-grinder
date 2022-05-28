// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends



// Problem : https://practice.geeksforgeeks.org/problems/shortest-path-between-cities/1



class Solution{   
public:
    int shortestPath(int x, int y) {
        int div1 = max(x,y);
        int div2 = min(x,y);
        int parent = -1, dist = 0;
        while (true) {
             while (div1 > div2) {
                div1 /= 2;
                dist++;
            }
            while (div2 > div1) {
                div2 /= 2;
                dist++;
            }
            if (div2 == div1) {
                parent = div2;
                break;
            }
        }
        return dist;
    }
};



// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        Solution ob;
        cout<< ob.shortestPath(x,y) << endl;
    }
    return 0; 
}   // } Driver Code Ends