class Solution_1 {
private:
    const static int N = 101;
    int dp[N][N];
    string str;
    int xs(int x) { return x == 1 ? 0 : x < 10 ? 1 : x < 100 ? 2 : 3; }
    int solve(int left, int k, int n) {
        if (k < 0) return N;
        if (left >= n || n - left <= k) return 0;
        int &res = dp[left][k];
        if (res != -1) return res;
        res = N;
        int cnt[26]{0};
        for (int j = left, most = 0; j < n; j++) {
            most = max(most, ++cnt[str[j] - 'a']);
            res = min(res, 1 + xs(most) + solve(j + 1, k - (j - left + 1 - most), n));
        }
        return res;
    }
public:
    int getLengthOfOptimalCompression(string &s, int k) {
        int n = s.size();
        memset(dp, -1, sizeof(dp));
        str = s;
        return solve(0, k, n);
    }
};



class Solution {
private:
    int dp[101][101];
    int dfs(string &s, int left, int K) {
        int k = K;
        if (s.size() - left <= k) return 0;
        if (dp[left][k] >= 0) return dp[left][k];
        int res = k ? dfs(s, left + 1, k - 1) : 101, c = 1;
        for (int i = left + 1; i <= s.size(); ++i) {
            int x = (c >= 100 ? 3 : (c >= 10 ? 2 : (c > 1 ? 1 : 0)));
            res = min(res, dfs(s, i, k) + 1 + x);
            if (i == s.size()) break;
            if (s[i] == s[left]) ++c;
            else if (--k < 0) break;
        }
        return dp[left][K] = res;
    }
public:
    int getLengthOfOptimalCompression(string &s, int k) {
        memset(dp, -1, sizeof(dp));
        return dfs(s, 0, k);
    }
};
