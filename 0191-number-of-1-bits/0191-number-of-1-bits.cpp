class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;                // count of set bit
        while (n > 0) {             // iterate until all bits are traversed
            cnt += ((n & 1) > 0);   // check the parity of first bit from right
            n >>= 1;                // shift one bit to right
        }
        return cnt;
    }
};
