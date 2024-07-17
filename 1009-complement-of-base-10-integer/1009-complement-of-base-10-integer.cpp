class Solution {
public:
    long long getNxtPowOf2(int n) {
        if ((int)log2(n) == log2(n)) {
            return n * 2;
        }
        long long pow = 1;
        while (pow<n) pow *= 2;
        return pow;
    }  
    long long bitwiseComplement(int num) {
        if (num==0) return 1;
        return getNxtPowOf2(num) - num -1; 
    }
};
