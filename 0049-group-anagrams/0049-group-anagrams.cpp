class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> anagrams;
        for (string &str : strs) {
            string t = str; 
            sort(t.begin(), t.end());
            mp[t].push_back(str);
        }
        for (auto &[key, val] : mp) { 
            anagrams.push_back(val);
        }
        return anagrams;
    }
};

