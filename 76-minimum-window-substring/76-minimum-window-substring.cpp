class Solution {
   public:
    string minWindow(string &s, string &t) {
        if (s.size() == 0 || t.size() == 0) return "";
        int remaining[128]{0};
        for (const char &c : t) remaining[c]++;
        int required = t.size();
        int min = INT_MAX, start = 0, left = 0, i = 0;
        while (i <= s.size() && start < s.size()) {
            if (required) {
                if (i == s.size()) break;
                remaining[s[i]]--;
                if (remaining[s[i]] >= 0) required--;
                i++;
            } else {
                if (i - start < min) {
                    min = i - start;
                    left = start;
                }
                remaining[s[start]]++;
                if (remaining[s[start]] > 0) required++;
                start++;
            }
        }
        return min == INT_MAX ? "" : s.substr(left, min);
    }
};
