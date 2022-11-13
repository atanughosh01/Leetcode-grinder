// O(n) time | O(n) space
class Solution_1 {
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
        int n = s.size(), i = 0, j = 0;
        while (i < n) {
            while (i < n && s[i] == ' ') i++;
            if (i < n && j > 0) s[j++] = ' ';
            int start = j;
            while (i < n && s[i] != ' ') s[j++] = s[i++];
            reverse(s.begin() + start, s.begin() + j);
        }
        s.resize(j);
        reverse(s.begin(), s.end());
        return s;
    }
};
