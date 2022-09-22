class Solution {
private:
    vector<string> split(string &s, const char &c) {
        int n = s.size(), l = 0, r = 0;
        s.push_back(c);
        vector<string> res;
        while (s[r] == c) r++;
        l = r;
        while (r < n) {
            while (s[r] != c) r++;
            string word = s.substr(l, r - l);
            res.push_back(word);
            while (s[r] == c) r++;
            l = r;
        }
        return res;
    }
public:
    string reverseWords(string &s) {
        vector<string> v = split(s, ' ');
        reverse(v[0].begin(), v[0].end());
        string res = v[0];
        for (int i = 1; i < v.size(); i++) {
            reverse(v[i].begin(), v[i].end());
            res += " " + v[i];
        }
        return res;
    }
};
