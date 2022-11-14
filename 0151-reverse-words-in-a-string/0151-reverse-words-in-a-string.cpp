// O(n) time | O(n) space
class Solution_1 {
private: 
    vector<string> split(string &s, const char &c) {
        int n = s.size(), l = 0, r = 0;
        s.push_back(c);
        vector<string> res;
        do {
            while (s[r] != c) r++;
            string word = s.substr(l, r - l);
            if (!word.empty()) {
                res.push_back(word);
            }
            while (s[r] == c) r++;
            l = r;
        } while (r < n);
        return res;
    }
public:
    string reverseWords(string &s) {
	    vector<string> v = split(s, ' ');
        string res = v.back();
        for (int i = v.size() - 2; i >= 0; i--) {
            res += " " + v[i];
        }
        return res;
    }
};



// O(n) time | O(1) space
class Solution {
public:
    string reverseWords(string &s) {
        int n = s.size(), r = 0, l = 0;
        while (r < n) {
            while (r < n && s[r] == ' ') r++;
            if (r < n && l > 0) s[l++] = ' ';
            int start = l;
            while (r < n && s[r] != ' ') s[l++] = s[r++];
            reverse(s.begin() + start, s.begin() + l);
        }
        s.resize(l);
        reverse(s.begin(), s.end());
        return s;
    }
};

