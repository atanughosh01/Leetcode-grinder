class Solution {
public:
    int minMoves2(vector<int> &nums) {
        int n = (int)(nums.size()), ans = 0;
        if (n == 1) return 0;
        if (n == 2) return abs(nums[1] - nums[0]);
        sort(nums.begin(), nums.end());
        if (n % 2) {
            int tar = nums[n/2];
            for (int num : nums) {
                ans += abs(tar - num);
            }
        } else {
            int tar1 = nums[n/2 - 1], a1 = 0;
            int tar2 = nums[n/2], a2 = 0;
            for (int num : nums) {
                a1 += abs(tar1 - num);
                a2 += abs(tar2 - num);
            }
            ans = min(a1, a2);
        }
        return ans;
    }
};
