class Solution {
public:
    string removeDuplicateLetters(string &s) {
        string res = "";
        int lastPos[26]{0}, n = s.size();
        bool added[26]{false};
        for (int i = 0; i < n; i++) lastPos[s[i] - 'a'] = i;
        for (int i = 0; i < n; i++) {
            if (added[s[i] - 'a']) continue;
            while (!res.empty() && res.back() > s[i] && lastPos[res.back() - 'a'] > i) {
                added[res.back() - 'a'] = false;
                res.pop_back();
            }
            res.push_back(s[i]);
            added[s[i] - 'a'] = true;
        }
        return res;
    }
};
