class Solution {
public:
    int findMaxConsecutiveOnes(vector<int> &nums) {
        int res = 0, cnt = 0;
        for (int &num : nums) {
            if (num) cnt++;
            else cnt = 0;
            res = max(res, cnt);
        }
        return res;
    }
};
