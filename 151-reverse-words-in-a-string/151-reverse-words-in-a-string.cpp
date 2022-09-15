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
