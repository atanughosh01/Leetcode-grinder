class Solution_1 {
public:
    double myPow(double x, int n) {
        if (n == 0 || x == 1.0) return 1.0;            
        double ans = 1.0;
        if (n > 0) {
            while (n--) {
                ans *= x;
            }
        } else {
            while (n++ < 0) {
                ans /= x;
            }
        }
        return ans;
    }
};



class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0) {
            x = 1 / x;
        } 
        long long num = labs(n);
        double pow = 1;
        while (num) {
            if (num & 1) {
                pow *= x;
            }
            x *= x;
            num >>= 1;
        }
        return pow;
    }
};
