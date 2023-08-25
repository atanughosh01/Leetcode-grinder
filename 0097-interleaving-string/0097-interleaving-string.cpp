class Solution_1 {
public:
    bool isInterleave(string &s1, string &s2, string &s3) {
        int m = s1.size(), n = s2.size();
        if (s3.size() != n + m) return false;
        bool table[m + 1][n + 1];
        for (int i = 0; i < m + 1; i++)
            for (int j = 0; j < n + 1; j++) {
                if (i == 0 && j == 0) {
                    table[i][j] = true;
                } else if (i == 0) {
                    table[i][j] = (table[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
                } else if (j == 0) {
                    table[i][j] = (table[i - 1][j] && s1[i - 1] == s3[i + j - 1]);
                } else {
                    table[i][j] = (table[i - 1][j] && s1[i - 1] == s3[i + j - 1]) ||
                        (table[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
                }
            }

        return table[m][n];
    }
};



class Solution {
public:
    bool isInterleave(string &s1, string &s2, string &s3) {
        int m = s1.size(), n = s2.size(), l = s3.size();
        if (m > n) return isInterleave(s2, s1, s3);
        if (l != m + n) return false;
        bool *dp = new bool[m + 1]();
        dp[0] = true;
        for (int i = 1; i <= m; i++) {
            dp[i] = dp[i - 1] && s3[i - 1] == s1[i - 1];
        }
        for (int j = 1; j <= n; j++) {
            dp[0] = dp[0] && s3[j - 1] == s2[j - 1];
            for (int i = 1; i <= m; i++) {
                dp[i] = (dp[i - 1] && s3[i + j - 1] == s1[i - 1]) ||
                        (dp[i] && s3[i + j - 1] == s2[j - 1]);
            }
        }
        return dp[m];
    }
};
