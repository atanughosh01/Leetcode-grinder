// Bruteforce | O(n) Time | O(2*n) Space
class Solution_1 {
public:
    vector<int> shuffle(vector<int> &nums, int n) {
        vector<int> res;
        for (int i = 0; i < n; i++) {
            res.push_back(nums[i]);
            res.push_back(nums[n + i]);
        }
        return res;
    }
};


// Optimal | O(2*n) == O(n) Time | O(1) Space
class Solution {
public:
    vector<int> shuffle(vector<int> &nums, int n) {
        for (int i = n; i < 2 * n; i++) {
            nums[i] = (nums[i] * 1024) + nums[i - n];
        }
        int idx = 0;
        for (int i = n; i < 2 * n; i++, idx += 2) {
            nums[idx] = nums[i] % 1024;
            nums[idx + 1] = nums[i] / 1024;
        }
        return nums;
    }
};
