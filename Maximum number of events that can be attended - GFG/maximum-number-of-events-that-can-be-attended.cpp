// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Problem : https://practice.geeksforgeeks.org/problems/ea8230731ccb057120bafb351c10c48b2d496125/1


class Solution {
  public:
    int maxEvents(int start[], int end[], int N) {
        vector<pair<int,int>> v;
        for(int i = 0; i < N; i++)
           v.push_back({start[i],end[i]});
        sort(v.begin(),v.end());
        priority_queue<int,vector<int>,greater<int>> pq;
        int cnt = 0;
        int i = 0, d = 0;
        while(!pq.empty() or i<N){
           if(pq.size() == 0)
               d = v[i].first;
           while(i<N and v[i].first <= d)
               pq.push(v[i++].second);
           pq.pop();
           cnt++;
           d++;
           while(!pq.empty() and pq.top() < d)
            pq.pop();
        }
        return (cnt);
    }
};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int start[N], end[N];
        for(int i=0; i<N; i++)
            cin>>start[i];
        for(int i=0; i<N; i++)
            cin>>end[i];

        Solution ob;
        cout << ob.maxEvents(start,end,N) << endl;
    }
    return 0;
}  // } Driver Code Ends