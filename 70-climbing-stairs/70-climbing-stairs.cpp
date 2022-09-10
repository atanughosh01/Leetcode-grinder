class Solution {
public:
    int climbStairs(int n) {
        int a = 1;
        long long temp, b = 1;
        while (n--) {
            temp = b;
            b += a;
            a = temp;
        }
        return a;
    }
};
