class Solution {
public:
    int lengthOfLastWord(string &s) {
        while (s.back() == ' ') s.pop_back();
        int len = 0, n = s.size();
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == ' ') break;
            len++;
        }
        return len;
    }
};
