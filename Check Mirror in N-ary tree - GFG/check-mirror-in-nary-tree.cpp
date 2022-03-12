// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



// Problem : https://practice.geeksforgeeks.org/problems/check-mirror-in-n-ary-tree1528/1


#define maxn 100001

class Solution {
public:
    int checkMirrorTree(int n, int e, int A[], int B[]) {
        vector<int>adj1[maxn],adj2[maxn];
        for(int i = 0 ; i < 2*e ; i += 2){
            A[i]-- , A[i + 1]--;
            adj1[A[i]].push_back(A[i + 1]);
            adj1[A[i + 1]].push_back(A[i]);
        }
        for(int i = 0 ; i  < 2*e ; i += 2){
            B[i]-- , B[i + 1]--;
            adj2[B[i]].push_back(B[i + 1]);
            adj2[B[i + 1]].push_back(B[i]);
        }
        queue<int>q1, q2;
        q1.push(0); q2.push(0);
        vector<int>vis1(n, 0), vis2(n, 0);
        vis1[0] = vis2[0] = 1;
        while(!q1.empty() && !q2.empty()){
            int p1 = q1.front() , p2= q2.front();
            q1.pop() , q2.pop();
            if(p1 != p2) return 0;
            for(int i = 0 ; i < adj1[p1].size() ; i++){
                if(vis1[adj1[p1][i]] == 0){
                    q1.push(adj1[p1][i]);
                    vis1[adj1[p1][i]] = 1;
                }
            }
            for(int i = adj2[p2].size() - 1 ; i >= 0 ; i--){
                if(vis2[adj2[p2][i]] == 0){
                    q2.push(adj2[p2][i]);
                    vis2[adj2[p2][i]] = 1;
                }
            }
        }
        return 1;
    }
};



// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,e;
        
        cin>>n>>e;
        int A[2*e], B[2*e];
        
        for(int i=0; i<2*e; i++)
            cin>>A[i];
            
        for(int i=0; i<2*e; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.checkMirrorTree(n,e,A,B) << endl;
    }
    return 0;
}  // } Driver Code Ends