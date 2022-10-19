class Solution {
private:
    void reverse(vector<int> &nums, int i, int j) {
        int li = i, ri = j;
        while (li <= ri) {
            swap(nums[li], nums[ri]);
            li++, ri--;
        }
    }
public :    
    void rotate(vector<int> &nums, int k) {
        int n = nums.size();
        k %= n;
        if (k < 0) k += n;
        reverse(nums, 0, n - k - 1);
        reverse(nums, n - k, n - 1);
        reverse(nums, 0, n - 1);
    }
};
