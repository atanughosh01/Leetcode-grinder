// Bruteforce
class Solution_1 {
public:
    int minSubArrayLen(int target, vector<int> &nums) {
        int n = nums.size();
        int res = INT_MAX, sum = 0;
        for (int i = 0; i < n; i++) {
            sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                if (sum >= target) {
                    res = min(res, j - i + 1);
                    break;
                }
            }
        }
        return (res == INT_MAX ? 0 : res);
    }
};



// Optimal
class Solution {
public:
    int minSubArrayLen(int target, vector<int> &nums) {
        int res = INT_MAX, n = nums.size();
        int l = 0, r = 0, sum = 0;
        while (r < n) {
            sum += nums[r];
            while (sum >= target) {
                res = min(res, r - l + 1);
                sum -= nums[l++];
            }
            r++;
        }
        return (res == INT_MAX ? 0 : res);
    }
};
