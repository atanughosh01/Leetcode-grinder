/*
    #define ll long long

    class Solution {
    private:
        ll count(string a, string b) {
            ll m = a.length(), n = b.length();
            vector<vector<ll>> dp(m+1, vector<ll>(n+1, 0));
            for (ll i = 0; i <= n; ++i) {
                dp[0][i] = 0;
            }
            for (ll i = 0; i <= m; ++i) {
                dp[i][0] = 1;
            }
            for (ll i = 1; i <= m; i++) {
                for (ll j = 1; j <= n; j++) {
                    if (a[i - 1] == b[j - 1]) {
                        dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                    } else {
                        dp[i][j] = dp[i - 1][j];
                    }
                }
            }
            return dp[m][n];
        }
    public:
        long long maximumSubsequenceCount(string t, string p) {
            string t1 = p[0] + t, t2 = t + p[1];
            ll ans1 = count(t1, p);
            ll ans2 = count(t2, p);
            return max(ans1, ans2);
        }
    };
*/


#define ll long long

class Solution {
public:
    long long maximumSubsequenceCount(string a, string b) {
        ll p1=0, p2=0;
        for(auto i : a) {
            if(i == b[0]) p1++;
            else if (i == b[1]) p2++;
        }
        if(p1 > p2) a.push_back(b[1]);
        else a = b[0] + a;
        ll m = a.length(), n = b.length();
        vector<vector<ll>> dp(m+1, vector<ll> (n+1, 0));
        for (ll i = 0; i <= n; ++i) {
            dp[0][i] = 0;
        }
        for (ll i = 0; i <= m; ++i) {
            dp[i][0] = 1;
        }
        for (ll i = 1; i <= m; i++) {
            for (ll j = 1; j <= n; j++) {
                if (a[i - 1] == b[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[m][n];
    }
};
