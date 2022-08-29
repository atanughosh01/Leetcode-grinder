class Solution {
public:    
    vector<int> twoSum(vector<int> &nums, int tar) {
        int l = 0, r = nums.size()-1;
        while (l <= r) {
            if(nums[l] + nums[r] == tar) {
                return {l+1, r+1};
            }
            else if (nums[l] + nums[r] > tar) r--;
            else l++;
        }
        return {};
    }
};
