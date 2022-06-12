class Solution {
public:
    int maxFrequency(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = n-1,j = n-1;
        int gap = 0, res = 1;
        while (i>=1 && j>=0) {
            gap += (nums[i] - nums[j]);
            if(gap <= k) {
                res = max(res, i+1-j);
                j--;
            } else {
                gap -= ((i - j)*(nums[i] - nums[i-1]));
                i--;
                gap -= (nums[i] - nums[j]);
            }
        }
        return res;
    }
};
