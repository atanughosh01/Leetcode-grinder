class Solution_1 {
public:
    string removeDuplicateLetters(string &s) {
        string res = "";
        int lastPos[26]{0}, n = s.size();
        bool visited[26]{false};
        for (int i = 0; i < n; i++) lastPos[s[i] - 'a'] = i;
        for (int i = 0; i < n; i++) {
            if (!visited[s[i] - 'a']) {
                while (!res.empty() && res.back() > s[i] && lastPos[res.back() - 'a'] > i) {
                    visited[res.back() - 'a'] = false;
                    res.pop_back();
                }
                res.push_back(s[i]);
                visited[s[i] - 'a'] = true;
            }
        }
        return res;
    }
};



class Solution {
public:
    string removeDuplicateLetters(string &s) {
        string res = "";
        int cnt[26]{0}, n = s.size();
        bool visited[26]{false};
        for (int i = 0; i < n; i++) cnt[s[i] - 'a']++;
        for (int i = 0; i < n; i++) {
            cnt[s[i] - 'a']--;
            if (!visited[s[i] - 'a']) {
                while (!res.empty() && res.back() > s[i] && cnt[res.back() - 'a'] > 0) {
                    visited[res.back() - 'a'] = false;
                    res.pop_back();
                }
                res.push_back(s[i]);
                visited[s[i] - 'a'] = true;
            }
        }
        return res;
    }
};
