class Solution {
public:
    string orderlyQueue(string &s, int k) {
        if (k >= 2) {
            sort(s.begin(), s.end());
            return s;
        }
        int n = s.size();
        string res = s;
        for (int i = 1; i < n; i++) {
            res = min(res, s.substr(i, n - i) + s.substr(0, i));
        }
        return res;
    }
};
