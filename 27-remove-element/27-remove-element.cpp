class Solution {
   public:
    int removeElement(vector<int> &nums, int val) {
        int len = nums.size(), idx = 0;
        while (idx < len) {
            if (nums[idx] == val) {
                nums[idx] = nums[len - 1];
                len--;
            } else {
                idx++;
            }
        }
        return len;
    }
};
