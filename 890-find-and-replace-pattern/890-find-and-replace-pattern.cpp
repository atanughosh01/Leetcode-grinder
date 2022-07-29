class Solution_1 {
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



class Solution_2 {
private:
    bool matches(string &w, string &p) {
        if (w.size() != p.size()) return false;
        char *wp = new char[26]{0};
        char *pw = new char[26]{0};
        for (int i = 0; i < w.size(); i++) {
            if (!wp[w[i] - 'a'] && !pw[p[i] - 'a']) {
                wp[w[i] - 'a'] = p[i];
                pw[p[i] - 'a'] = w[i];
            } else if (wp[w[i]-'a'] == p[i] && pw[p[i]-'a'] == w[i]) {
                continue;
            } else {
                delete [] wp;
                delete [] pw;
                return false;
            }
        }
        delete [] wp;
        delete [] pw;
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



class Solution {
private:
    string newPattern(string w) {
        unordered_map<char, int> m;
        for (char &c : w) {
            if (!m.count(c)) {
                m[c] = m.size();
            }
        }
        for (int i = 0; i < w.size(); ++i) {
            w[i] = 'a' + m[w[i]];
        }
        return w;
    }
public:
    vector<string> findAndReplacePattern(vector<string> &words, string &pattern) {
        vector<string> res;
        pattern = newPattern(pattern);
        for (string &word : words) {
            if (newPattern(word) == pattern) {
                res.push_back(word);
            }
        }
        return res;
    }
};
