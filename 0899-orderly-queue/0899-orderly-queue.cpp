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
            string x = s.substr(i, n - i) + s.substr(0, i);
            res = min(res, x);
        }
        return res;
    }
};
