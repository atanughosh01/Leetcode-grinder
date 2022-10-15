class Solution {
private:
    const static int N = 101;
    int dp[N][N];
    string str;
    int xs(int x) { return x == 1 ? 0 : x < 10 ? 1 : x < 100 ? 2 : 3; }
    int solve(int left, int k, int &n) {
        if (k < 0) return N;
        if (left >= n or n - left <= k) return 0;
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
