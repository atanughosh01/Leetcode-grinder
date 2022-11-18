class Solution_1 {
public:
    bool isUgly(int n) {
        if (n <= 0) return false;
        while (n % 2 == 0) n /= 2;
        while (n % 3 == 0) n /= 3;
        while (n % 5 == 0) n /= 5;
        return n == 1;
    }
};



class Solution {
private:
    int keepDividingWhenDivisible(int dividend, int divisor) {
        while (dividend % divisor == 0) {
            dividend /= divisor;;
        }
        return dividend;
    }
public:
    bool isUgly(int n) {
        if (n <= 0) return false;
        for (int factor : {2, 3, 5}) {
            n = keepDividingWhenDivisible(n, factor);
        }
        return n == 1;
    }
};
