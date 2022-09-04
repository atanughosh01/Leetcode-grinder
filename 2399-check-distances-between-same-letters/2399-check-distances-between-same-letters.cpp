// O(n) time, O(n) space, n = s.length
class Solution_1 {
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


// O(n) time, O(1) space, n = s.length
class Solution {
public:
    bool checkDistances(string &s, vector<int> &dist) {
        int pos[26]{0};
        for (int i = 0; i < s.size(); ++i) {
            int n = s[i] - 'a';
            if (pos[n] > 0 && dist[n] + pos[n] != i) {
                return false;
            }
            pos[n] = i + 1;
        }
        return true;
    }
};
