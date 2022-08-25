class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int res = INT_MIN, sum = 0;
        for (int num : nums){
            int temp = sum + num;
            sum = max(num, temp);
            res = max(res, sum);
        }
        return res;
    }
};
