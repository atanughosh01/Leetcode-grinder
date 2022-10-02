class Solution_1 {
public:
    int commonFactors(int a, int b) {
        int g = __gcd(a, b), cnt = 0;
        for (int i = 1; i <= g; i++) {
            cnt += (g % i == 0);
        }
        return cnt;
    }
};



class Solution {
public:
    int commonFactors(int a, int b) {
        a = __gcd(a, b);
        int sr = sqrt(a);
        int res = sr * sr == a ? -1 : 0;
        for (int i = 1; i <= sr; ++i) {
            res += 2 * (a % i == 0);
        }
        return res;
    }
};
