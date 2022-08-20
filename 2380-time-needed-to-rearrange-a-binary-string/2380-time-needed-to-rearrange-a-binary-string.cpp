class Solution {
public:
    int secondsToRemoveOccurrences(string &s) {
        int res = 0, n = s.size();
        for (int i = 0; i < n; i++) {
            bool flag = false;
            for (int j = 0; j < n - 1; j++) {
                if (s[j] == '0' && s[j + 1] == '1') {
                    flag = true;
                    swap(s[j], s[j + 1]);
                    j++;
                }
            }
            if (flag) res++;
            else break;
        }
        return res;
    }
};
