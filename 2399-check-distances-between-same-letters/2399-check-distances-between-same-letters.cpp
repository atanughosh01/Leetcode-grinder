class Solution {
public:
    bool checkDistances(string &s, vector<int> &dist) {
        unordered_map<char, vector<int>> mp;
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]].push_back(i);
        }
        for (auto &[key, val] : mp) {
            if (dist[key - 'a'] != abs(val[1] - val[0] - 1)) {
                return false;
            }
        }
        return true;
    }
};
