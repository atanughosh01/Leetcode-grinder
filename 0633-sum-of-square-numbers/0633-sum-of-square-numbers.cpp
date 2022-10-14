class Solution_1 {
public:
    bool judgeSquareSum(int &c) {
        for (long long a = 0; a * a <= c; a++) {
            for (long long b = 0; b * b <= c; b++) {
                if (a * a + b * b == c) {
                    return true;
                }
            }
        }
        return false;
    }
};



class Solution_2 {
public:
    bool judgeSquareSum(int &c) {
        for (long long a = 0; a * a <= c; a++) {
            long long b = c - (int)(a * a), s = 0;
            for (long long i = 1; s < b; i += 2) s += i;
            if (s == b) return true;
        }
        return false;
    }
};



class Solution_3 {
public:
    bool judgeSquareSum(int &c) {
        for (long long a = 0; a * a <= c; a++) {
            long double b = sqrt(c - (a * a));
            if ((long long)b == b) return true;
        }
        return false;
    }
};



class Solution {
public:
    bool judgeSquareSum(int &c) {
        long long l = 0, r = sqrt(c);
        while (l <= r) {
            long long curr = l * l + r * r;
            if (curr == c) return true;
            else if (curr < c) l++;
            else r--;
        }
        return false;
    }
};
