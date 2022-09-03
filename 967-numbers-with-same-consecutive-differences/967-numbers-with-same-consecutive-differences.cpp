class Solution_1 {
private:
    bool isValid(int num, int k) {
        int x = num, a = 0, b = 0;
        while (x / 10) {
            a = x % 10;
            x /= 10;
            b = x % 10;
            if (abs(a - b) != k) {
                return false;
            }
        }
        return true;
    }
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> res;
        int l = pow(10, n - 1), r = pow(10, n);
        for (int i = l; i < r; i++) {
            if (isValid(i, k)) {
                res.push_back(i);
            }
        }
        return res;
    }
};



class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> cur = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        for (int i = 2; i <= n; ++i) {
            vector<int> cur2;
            for (int x : cur) {
                int y = x % 10;
                if (y + k < 10) {
                    cur2.push_back(x * 10 + y + k);
                }
                if (k > 0 && y - k >= 0) {
                    cur2.push_back(x * 10 + y - k);
                }
            }
            cur = cur2;
        }
        return cur;
    }
};
