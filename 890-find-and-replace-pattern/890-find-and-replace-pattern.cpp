class Solution {
private:
    bool matches(string &w, string &p) {
        if (w.size() != p.size()) return false;
        unordered_map<char, char> wp, pw;
        for (int i = 0; i < w.size(); i++) {
            if (!wp.count(w[i]) && !pw.count(p[i])) {
                wp[w[i]] = p[i];
                pw[p[i]] = w[i];
            } else if (wp[w[i]] == p[i] && pw[p[i]] == w[i]) {
                continue;
            } else {
                return false;
            }
        }
        return true;
    }
public:
    vector<string> findAndReplacePattern(vector<string> &words, string &pattern) {
        vector<string> res{};
        for (string &word : words) {
            if (matches(word, pattern)) {
                res.push_back(word);
            }
        }
        return res;
    }
};
