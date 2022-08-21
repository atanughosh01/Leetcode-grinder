class Solution_1 {
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




class Solution {
public:
    int secondsToRemoveOccurrences(string &s) {
        int zeros = 0, seconds = 0;
        for (int i = 0; i < s.size(); i++) {
            zeros += s[i] == '0';
            if (s[i] == '1' && zeros) {
                seconds = max(seconds + 1, zeros);
            }
        }
        return seconds;
    }
};
