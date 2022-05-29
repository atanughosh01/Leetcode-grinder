/*
    class Solution {
    public:
        int maxProduct(vector<string> &words) {
            int best = 0, n = words.size();
            vector<int> bitsets(n);
            for (int i = 0; i < n; i++) {
                string word = words[i];
                int bitset = 0;
                for (char &c : word) {
                    bitset |= (1 << (c - 'a'));
                }
                for (int j = 0; j < i; j++) {
                    if ((bitsets[j] & bitset) == 0) {
                        int temp = (int)(word.size() * words[j].size());
                        best = max(best, temp);
                    }
                }
                bitsets[i] = bitset;
            }
            return best;
        }
    };
*/


class Solution {
public:
    int maxProduct(vector<string> &words) {
        int ans = 0, n = words.size();
        vector<vector<int>> dp(n, vector<int>(26));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < words[i].size(); j++) {
                dp[i][words[i][j] - 'a']++;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                bool common = true;
                for (int k = 0; k < 26; k++) {
                    if (dp[i][k] > 0 && dp[j][k] > 0) {
                        common = false;
                    }
                }
                if (common) {
                    int cur = words[i].size() * words[j].size();
                    ans = max(ans, cur);
                }
            }
        }
        return ans;
    }
};
