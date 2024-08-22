class Solution {
public:
    long long getNxtPowOf2(int n) {
        if ((int)log2(n) == log2(n)) {
            return n*2;
        }
        long long pow = 1;
        while (pow < n) pow *= 2;
        return pow;
    }
    long long findComplement(int num) {
        return getNxtPowOf2(num) - num -1; 
    }
};
