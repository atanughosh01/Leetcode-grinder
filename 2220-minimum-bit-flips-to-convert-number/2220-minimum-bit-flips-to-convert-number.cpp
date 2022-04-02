class Solution {
private:
    int countSetBits(int n) {
        int count = 0;
        while (n) {
            count++;
            n &= (n-1);
        }
        return count;
    }
public:
    int minBitFlips(int start, int goal) {
        return countSetBits(start ^ goal);
    }
};
