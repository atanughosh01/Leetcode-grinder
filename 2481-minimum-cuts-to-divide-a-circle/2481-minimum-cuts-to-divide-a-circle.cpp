class Solution {
public:
    int numberOfCuts(int n) {
        if (n == 1) return 0;
        if (n == 3) return 3;
        return ((n % 2) ? n : n / 2);
    }
};
