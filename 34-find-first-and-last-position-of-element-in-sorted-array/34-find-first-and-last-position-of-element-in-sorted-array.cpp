class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        int n = (int)(nums.size());
        int first = -1, last = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] == target && first == -1) {
                first = i;
            }
            if (nums[n-i-1] == target && last == -1) {
                last = n-i-1;
            }
            if (first != -1 && last != -1) {
                break;
            }
        }
        return {first, last};
    }
};
