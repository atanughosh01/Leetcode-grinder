class Solution_1 {
public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;
        return tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
    }
};


class Solution_2 {
public:
    int tribonacci(int n) {
        if (n < 2) return n;
        int a = 0, b = 1, c = 1;
        while (n-- > 2) {
            int d = a + b + c;
            a = b;
            b = c;
            c = d;
        }
        return c;
    }
};


class Solution {
public:
    int tribonacci(int n) {
        int dp[3] = {0, 1, 1};
        for (int i = 3; i <= n; ++i) {
            dp[i % 3] = dp[0] + dp[1] + dp[2];
        }
        return dp[n % 3];
    }
};
