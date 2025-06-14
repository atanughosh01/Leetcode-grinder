class Solution {
public:
    long long zeroFilledSubarray(vector<int> &nums) {
        long long res = 0, cnt = 0;
        for (int num : nums) {
            if (num == 0) {
                cnt++;
                res += cnt;
            } else {
                cnt = 0;
            }
        }
        return res;
    }
};
