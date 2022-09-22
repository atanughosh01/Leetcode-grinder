class Solution {
private:
    vector<string> splitAndReverse(string &s, const char &c) {
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
        for (string &x : res) reverse(x.begin(), x.end());
        return res;
    }
public:
    string reverseWords(string &s) {
        vector<string> v = splitAndReverse(s, ' ');
        string res = v[0];
        for (int i = 1; i < v.size(); i++) {
            res += " " + v[i];
        }
        return res;
    }
};
