class Solution {
private:
    int expandAroundCenter(string &s, int left, int right) {
        int L = left, R = right;
        while (L >= 0 && R < s.size() && s[L] == s[R]) {
            L--;
            R++;
        }
        return R - L - 1;
    }
public:
    string longestPalindrome(string &s) {
        int n = s.size();
        if (n == 0) return "";
        int start = 0, end = 0;
        for (int i = 0; i < n; i++) {
            int len1 = expandAroundCenter(s, i, i);
            int len2 = expandAroundCenter(s, i, i+1);
            int len = max(len1, len2);
            if (len > end - start) {
                start = i - (len - 1)/2;
                end = i + len/2;
            }
        }
        return s.substr(start, end - start + 1);        
    }
};
