// O(n) time | O(n) space
class Solution {
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
