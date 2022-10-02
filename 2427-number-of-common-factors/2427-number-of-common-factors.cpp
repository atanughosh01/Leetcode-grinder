class Solution {
public:
    int commonFactors(int a, int b) {
        int g = __gcd(a, b), cnt = 0;
        for (int i = 1; i <= g; i++) {
            cnt += (g % i == 0);
        }
        return cnt;
    }
};
