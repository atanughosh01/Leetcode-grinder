class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        double y = log2(n);
        return (y - int(y)) == 0;
    }
};
