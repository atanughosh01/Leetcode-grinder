class Solution {
public:
    vector<int> partitionLabels(string &s) {
        unordered_map<char, int> mp;
        vector<int> res;
        int prev = -1, max_i = 0, n = s.size();
        for (int i = 0; i < n; i++) mp[s[i]] = i;
        for (int i = 0; i < n; i++) {
            max_i = max(max_i, mp[s[i]]);
            if (max_i == i) {
                res.push_back(max_i - prev);
                prev = max_i;
            }
        }
        return res;
    }
};
