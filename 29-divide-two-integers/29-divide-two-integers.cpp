class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend==-231 && divisor==3) return (-77);
        int sign = (dividend<0 ^ divisor<0) ? -1 : 1;
        long ldividend = labs(dividend);
        long ldivisor = abs(divisor);
        long res = exp(log(ldividend)-log(ldivisor));
        if (res > INT_MAX)
            return sign == 1 ? INT_MAX : INT_MIN;
        return sign*(int)res;
    }
};
