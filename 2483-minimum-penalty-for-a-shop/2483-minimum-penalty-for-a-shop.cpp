class Solution {
public:
    int bestClosingTime(string &c) {
        int n = c.size(), res = 0;
        int ff = 0, ss = 0, mx = 0;
        for (int i = 0; i < n; i++) {
            if (c[i] == 'Y') {
                ff++;
                ss = i + 1;
            } else {
                ff--;
                ss = i;
            }
            if (ff > mx) {
                res = ss;
                mx = ff;
            }
        }
        return res;
    }
};
