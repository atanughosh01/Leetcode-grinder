// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Problem : https://practice.geeksforgeeks.org/problems/bbd15e2da95880979ce65acc7360e2c5681664e65520/1


class Solution{
public:
    vector<int> TopK(vector<int>& array, int k){
        unordered_map<int,int> mp;
        for(int i = 0;i<array.size();i++){
            mp[array[i]]++;
        }
        vector<pair<int,int>> v;
        for(auto a : mp){
            v.push_back({a.first,a.second});
        }
        sort(v.begin(),v.end(), [](const pair<int,int> &a, const pair<int,int> &b)->bool{
            return a.second > b.second || (a.second == b.second && a.first > b.first);
        });
        vector<int>res;
        for(auto a : v) if(k-- == 0) return res; else res.push_back(a.first);
        return res;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k ;
        cin>>n;
        
        vector<int>array(n);
        
        for(int i=0; i<n; i++)
            cin>>array[i];
            
        cin>>k;
        
        Solution obj;
        vector<int> result = obj.TopK(array,k);
        
        for(int i=0; i<result.size();i++)
            cout<<result[i]<<" ";

        cout<<"\n";

    }
    return 0;
}  // } Driver Code Ends