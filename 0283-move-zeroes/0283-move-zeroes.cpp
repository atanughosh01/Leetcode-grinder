class Solution_1 {
public:
    void moveZeroes(vector<int> &nums) {
        int cnt = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == 0) {
                cnt++;
                nums.erase(nums.begin() + i, nums.begin() + i + 1);
                i--;
            }
        }
        while (cnt--) nums.push_back(0);
    }
};


class Solution {
public:
    void moveZeroes(vector<int> &nums) {
        int n = nums.size();
        if (n <= 1) return;
        int z = 0, j = 1;
        while (j < n) {
            if (nums[z] == 0 && nums[j] != 0) {
                swap(nums[z], nums[j]);
                z++;               
            }
            if (nums[z] != 0) z++;
            j++;
        }
    }
};
