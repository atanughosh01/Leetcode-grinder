class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int n = digits.size(), i = n - 1;
        while (i >= 0) {
            digits[i]++;
            if (digits[i] >= 10) {
                digits[i--] %= 10;
            } else break;
        }
        if (i == -1) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
