class Solution {
public:
    int climbStairs(int n) {
        long long temp, b = 1, a = 1;
        while (n--) {
            temp = b;
            b += a;
            a = temp;
        }
        return a;
    }
};
