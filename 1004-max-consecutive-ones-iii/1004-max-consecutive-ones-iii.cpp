// Max Consecutive Ones II : https://www.lintcode.com/problem/883/


class Solution {
public:
    int longestOnes(vector<int> &nums, int k) {
        int res = 0, n = nums.size();
        int cnt = 0, l = 0, r = 0;
        while (r < n) {
            cnt += (nums[r] == 0);
            if (cnt > k) {
                cnt -= (nums[l++] == 0);
            }
            res = r - l + 1;
            r++;
        }
        return res;
    }
};
