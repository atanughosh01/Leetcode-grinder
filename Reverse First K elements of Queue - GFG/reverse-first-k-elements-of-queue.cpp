// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
queue<int> modifyQueue(queue<int> q, int k);
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        queue<int> ans = modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}// } Driver Code Ends


// User function Template for C++

// Function to reverse first k elements of a queue.
queue<int> modifyQueue(queue<int> q, int k) {
  
  int n=q.size();
   stack<int>s;   //using stack to reverse the desired portion  and rest ele of q are used in vector
   vector<int>v;
  while(k--)
  {
      s.push(q.front());
      q.pop();
  }
  while(!q.empty())
  {
      v.push_back(q.front());
      q.pop();
  }
  
  while(!s.empty())
  {
      q.push(s.top()); s.pop();
  }
  for(int i=0;i<v.size();i++)
  {
      q.push(v[i]);
  }
  return q;
  
  
}