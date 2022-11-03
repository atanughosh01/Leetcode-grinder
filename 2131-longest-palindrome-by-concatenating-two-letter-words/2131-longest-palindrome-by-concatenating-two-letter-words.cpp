class Solution {
public:
    int longestPalindrome(vector<string> &words) {
        constexpr int sz = 26;
        int res = 0;
        bool central = false;
        vector count(sz, vector<int>(sz, 0));
        for (auto &word : words) {
            count[word[0] - 'a'][word[1] - 'a']++;
        }
        for (int i = 0; i < sz; i++) {
            if (count[i][i] % 2 == 0) {
                res += count[i][i];
            } else {
                res += count[i][i] - 1;
                central = true;
            }
            for (int j = i + 1; j < sz; j++) {
                res += 2 * min(count[i][j], count[j][i]);
            }
        }
        if (central) res++;
        return 2 * res;
    }
};
