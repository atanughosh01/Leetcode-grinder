class Solution {
public:
    int findMaxConsecutiveOnes(vector<int> &nums) {
        int n = nums.size(), res = 0, cnt = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i]) cnt++;
            else cnt = 0;
            res = max(res, cnt);
        }
        return res;
    }
};
