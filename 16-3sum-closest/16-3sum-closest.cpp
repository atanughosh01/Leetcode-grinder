// Optimal | O(n^2) time | O(1) space | Two Pointers
class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        int res = nums[0] + nums[1] + nums[2];
        int n = nums.size(), l = 0, r = n - 1;
        for (int i = 0; i < n; i++) {
            l = i + 1, r = n - 1;
            while (l < r) {
                int sum = (nums[i] + nums[l] + nums[r]);
                if (abs(target - res) >  abs(target - sum)) {
                    res = sum;
                }
                if (sum < target) l++;
                else if (sum > target) r--;
                else return target;
            }
        }
        return res;
    }
};
