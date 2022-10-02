class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int set1 = __builtin_popcount(num1);
        int set2 = __builtin_popcount(num2);
        int res = 0;
        for (int i = 0; i <= 31; i++) {
            int mask = 1 << i, set = num1 & mask;
            if (set == 0 && set2 > set1) {
                res |= mask;
                set2--;
            } else if (set && set1 > set2) set1--;
            else res |= set;
        }
        return res;
    }
};
