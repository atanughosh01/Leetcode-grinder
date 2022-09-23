class Solution {
public:
    int concatenatedBinary(int n) {
        const long long MOD = 1e9 + 7;
        long long res = 0;
        for (long long i = 1, shift = 0; i <= n; i++) {
            shift +=  ((i & (i-1)) == 0);
            res <<= shift;
            res += i;
            res %= MOD;
        }
        return (int)res;
    }
};
