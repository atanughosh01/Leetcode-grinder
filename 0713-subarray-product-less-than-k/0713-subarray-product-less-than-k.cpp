class Solution {
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k) {
        if (k == 0 || k == 1) return 0;
        int n = nums.size(), res = 0;
        int l = 0, r = 0, pdt = 1;
        while (r < n) {
            pdt *= nums[r];
            while (pdt >= k) {
                pdt /= nums[l];
                l++;
            }
            res += (r - l + 1);
            r++;
        }        
        return res;
    }
};
