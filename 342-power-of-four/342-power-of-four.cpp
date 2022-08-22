class Solution_1 {
public:
    bool isPowerOfFour(int n) {
        long long a = 1;
        while (a < n) a *= 4;
        return a == n;
    }
};



class Solution {
public:
    bool isPowerOfFour(int num) {
        long long n = (long long)num;
        return (((n - 1) & n) == 0) && ((n - 1) % 3 == 0);
    }
};
