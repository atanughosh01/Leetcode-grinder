class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n < 1) return false;
        double x = log2(n);
        return ((x - int(x)) == 0);
    }
};
