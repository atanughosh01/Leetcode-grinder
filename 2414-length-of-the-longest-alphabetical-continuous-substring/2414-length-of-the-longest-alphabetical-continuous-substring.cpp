class Solution {
public:
    int longestContinuousSubstring(string &s) {
        int mx = INT_MIN, len = 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] - s[i-1] == 1) {
                len++;
                mx = max(len, mx);
            } else {
                len = 1;
            }
        }
        mx = max(mx, len);
        return mx;
    }
};
