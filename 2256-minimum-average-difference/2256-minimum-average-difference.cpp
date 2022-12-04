class Solution {
public:
    int minimumAverageDifference(vector<int> &nums) {
        int n = nums.size(), res = -1, mn = INT_MAX;
        long long curPreSum = 0, totalSum = 0;
        for (int &x : nums) totalSum += x;
        for (int i = 0; i < n; ++i) {
            curPreSum += nums[i];
            long long leftPartAvg = curPreSum;
            long long rightPartAvg = totalSum - curPreSum;
            leftPartAvg /= (i + 1);
            if (i != n - 1) rightPartAvg /= (n - i - 1);
            int curDiff = int(abs(leftPartAvg - rightPartAvg));
            if (curDiff < mn) {
                mn = curDiff;
                res = i;
            }
        }
        return res;
    }
};
