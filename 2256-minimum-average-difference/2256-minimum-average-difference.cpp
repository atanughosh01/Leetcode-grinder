class Solution {
public:
    int minimumAverageDifference(vector<int> &nums) {
        int n = nums.size(), res = -1;
        int minAvgDiff = numeric_limits<int>::max();
        long long curPreSum = 0, totalSum = 0;
        for (int &x : nums) totalSum += x;
        for (int i = 0; i < n; ++i) {
            curPreSum += nums[i];
            long long leftPartAvg = curPreSum;
            long long rightPartAvg = totalSum - curPreSum;
            leftPartAvg /= (i + 1);
            if (i != n - 1) rightPartAvg /= (n - i - 1);
            int curDiff = int(abs(leftPartAvg - rightPartAvg));
            if (curDiff < minAvgDiff) {
                minAvgDiff = curDiff;
                res = i;
            }
        }
        return res;
    }
};
