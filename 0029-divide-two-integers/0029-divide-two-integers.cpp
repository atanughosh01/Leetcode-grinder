class Solution {
public:
	int divide(int dividend, int divisor) {
		if (dividend == divisor) return 1;
		bool isPositive = (dividend < 0 == divisor < 0);  // if both are of same sign, answer is positive
		unsigned int a = abs(dividend);
		unsigned int b = abs(divisor);
		unsigned int ans = 0;
		while (a >= b) {  // while dividend is greater than or equal to divisor
			short q = 0;
			while (a > (b << (q + 1))) q++;
			ans += (1ll << q); // add the power of 2 found to the answer
			a -= (b << q); // reduce the dividend by divisor * power of 2 found
		}
		if (ans == (1ll << 31) && isPositive) return INT_MAX; // if ans cannot be stored in signed int
		return isPositive ? ans : -ans;
	}
};
