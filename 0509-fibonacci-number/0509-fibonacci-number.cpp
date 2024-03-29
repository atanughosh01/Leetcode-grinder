class Solution_1 {
public:
    int fib(int n) {
        if (n <= 1) return n;
        return fib(n - 1) + fib(n - 2);
    }
};


class Solution_2 {
public:
    int fib(int n) {
        if (n <= 1) return n;
        int prev2 = 0, prev1 = 1, cur;
        for (int i = 2; i <= n; i++) {
            cur = prev2 + prev1;
            prev2 = prev1;
            prev1 = cur;
        }
        return cur;
    }
};


class Solution {
public:
    int fib(int n) {
        double ratio = (sqrt(5) + 1) / 2;
        double uptopowers = 1;
        while (n > 0) {
            if (n & 1) uptopowers *= ratio;
            ratio *= ratio;
            n >>= 1;
        }
        return round(uptopowers/sqrt(5));
    }
};
