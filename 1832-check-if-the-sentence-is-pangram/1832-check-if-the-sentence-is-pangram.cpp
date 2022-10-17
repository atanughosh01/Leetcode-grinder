class Solution {
public:
    bool checkIfPangram(string &s) {
        int cnt[26]{0};
        for (char &c : s) cnt[c-'a']++;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] == 0) {
                return false;
            }
        }
        return true;
    }
};
