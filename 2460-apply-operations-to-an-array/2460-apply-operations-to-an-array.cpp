// O(n) time | O(n) space
class Solution_1 {
public:
    vector<int> applyOperations(vector<int> &nums) {
        int n = nums.size();
        vector<int> res;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }
        for (int &x : nums) {
            if (x != 0) {
                res.push_back(x);
            }
        }
        for (int &x : nums) {
            if (x == 0) {
                res.push_back(x);
            }
        }
        return res;
    }
};



// O(n) time | O(1) space
class Solution {
public:
    vector<int> applyOperations(vector<int> &nums) {
        int n = nums.size(), j = 0;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }
        for (int &x : nums) {
            if (x != 0) {
                nums[j++] = x;
            }
        }
        while (j < n) nums[j++] = 0;
        return nums;
    }
};
