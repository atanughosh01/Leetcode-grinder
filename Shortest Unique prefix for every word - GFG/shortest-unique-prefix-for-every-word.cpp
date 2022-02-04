// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


// Problem : https://practice.geeksforgeeks.org/problems/shortest-unique-prefix-for-every-word/1


class Solution {
private:
    struct TrieNode {
        TrieNode* child[26];
        int cnt;
        TrieNode() {
            for(int i = 0; i < 26; i++) {
                child[i] = NULL;
            }
            cnt = 0;
        }
    };
    
    void insert(string str, TrieNode* root) {
        int n = (int)str.size();
        TrieNode* curr = root;
        for(int i=0; i<n; i++) {
            int idx = str[i] - 'a';
            if(curr->child[idx] == NULL) {
                curr -> child[idx] = new TrieNode();
            }
            curr->cnt++;
            curr = curr->child[idx];
        }
    }
    
    string get_prefix(string str, TrieNode* root) {
        TrieNode* curr = root;
        int n = (int)str.size();
        string prefix = "";
        for(int i = 0; i < n; i++) {
            int idx = str[i] - 'a';
            if(curr->cnt == 1)
                break;
            prefix += str[i];
            curr = curr->child[idx];
        }
        return prefix;
    }

public:
    vector<string> findPrefixes(string arr[], int n) {
        TrieNode* root = new TrieNode();
        for(int i = 0; i < n; i++) {
            insert(arr[i], root);
        }
        vector<string> res;
        for(int i = 0; i < n; i++) {
            string temp = get_prefix(arr[i], root);
            res.emplace_back(temp);
        }
        return res;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        string arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
            
        Solution ob;
        vector<string> ans = ob.findPrefixes(arr, n);
        
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] <<" ";


        cout << "\n";

    }

    return 0;
}
  // } Driver Code Ends