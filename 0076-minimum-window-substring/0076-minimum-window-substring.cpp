class Solution {
public:
    string minWindow(string &s, string &t) {
        int rem[128]{0}, req = t.size(), m = s.size();
        int min = INT_MAX, start = 0, left = 0, i = 0;
        for (char &c : t) rem[c]++;
        while (i <= m && start < m) {
            if (req) {
                if (i == m) break;
                if (rem[s[i]]-- >= 1) req--;
                i++;
            } else {
                if (i - start < min) {
                    min = i - start;
                    left = start;
                }
                if (rem[s[start]]++ >= 0) req++;
                start++;
            }
        }
        return (min == INT_MAX) ? "" : s.substr(left, min);
    }
};
