class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int res = INT_MIN, sum = 0;
        for (int i = 0; i < nums.size(); i++){
            int temp = sum + nums[i];
            sum = max(nums[i], temp);
            res = max(res, sum);
        }
        return res;
    }
};
