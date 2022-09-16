class Solution_1 {
public:
    int countOdds(int low, int high) {
        int cnt = 0;
        for (int i = low; i <= high; i++) {
            if (i % 2) cnt++;
        }
        return cnt;
    }
};



class Solution {
public:
    int countOdds(int low, int high) {
        int d = high - low;
        if (low % 2 == 0 && high % 2 == 0)
            return d / 2;
        return d / 2 + 1;
    }
};
