//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends



// Problem : https://practice.geeksforgeeks.org/problems/phone-directory4628/1



class TrieNode {
public:
	TrieNode *child[26];
	bool isEnd;
	TrieNode() {
		for (int i = 0; i < 26; i++) {
			child[i] = nullptr;
		}
		isEnd = false;
	}
};


class Trie {
	TrieNode *root;
public:
	Trie() {
		root = new TrieNode();
	}
	void insert(string &s) {
		TrieNode *curr = root;
		for (int i = 0; i < s.length(); i++) {
			int index = s[i] - 'a';
			if (curr->child[index] == nullptr)
				curr->child[index] = new TrieNode();
			curr = curr->child[index];
		}
		curr->isEnd = true;
	}
	void dfs(string s, TrieNode *curr, vector<string> &vec) {
		if (curr->isEnd) vec.push_back(s);
		for (int i = 0; i < 26; i++) {
			if (curr->child[i] != nullptr) {
				s += ('a' + i);
				dfs(s, curr->child[i], vec);
				s.pop_back();
			}
		}
	}
	vector<string> findit(string pre) {
		TrieNode *curr = root;
		for (int i = 0; pre[i] != '\0'; i++) {
			int idx = pre[i] - 'a';
			if (!curr->child[idx]) return {"0"};
			else curr = curr->child[idx];
		}
		vector<string> vec;
		dfs(pre, curr, vec);
		return vec;
	}
};


class Solution {
public:
	vector<vector<string>> displayContacts(int n, string *contact, string &s) {
		Trie trie;
		vector<vector<string>> res;
		for (int i = 0; i < n; i++) {
			trie.insert(contact[i]);
		}
		for (int i = 0; i < s.size(); i++) {
			auto it = trie.findit(s.substr(0, i + 1));
			res.push_back(it);
		}
		return res;
	}
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends