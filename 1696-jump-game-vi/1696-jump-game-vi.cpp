class Solution_1 {
public:
    int maxResult(vector<int> &nums, int k, int i = 0) {
        if (i >= nums.size() - 1) return nums.back();
        int score = INT_MIN;
        for (int j = 1; j <= k; j++) {
            score = max(score, nums[i] + maxResult(nums, k, i + j));
        }
        return score;
    }
};



class Solution_2 {
private:
    int solve(vector<int> &nums, vector<int> &dp, int k, int i) {
        if(dp[i] != INT_MIN) return dp[i];
        for (int j = 1; j <= k; j++) {
            if (i + j < nums.size()) {
                dp[i] = max(dp[i], nums[i] + solve(nums, dp, k, i + j));
            }
        }
        return dp[i];
    }
public:
    int maxResult(vector<int> &nums, int k) {
        vector<int> dp(nums.size(), INT_MIN);
        dp.back() = nums.back();
        return solve(nums, dp, k, 0);
    }
};



class Solution_3 {
public:
    int maxResult(vector<int> &nums, int k) {
        vector<int> dp(nums.size(), INT_MIN);
        dp[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 1; j <= k && i - j >= 0; j++) {
                dp[i] = max(dp[i], dp[i - j] + nums[i]);
            }
        }
        return dp.back();
    }
};



class Solution {
public:
    int maxResult(vector<int> &nums, int k) {
        vector<int> dp(nums.size(), INT_MIN);
        multiset<int> s({dp[0] = nums[0]});
        for (int i = 1; i < size(nums); i++) {
            if (i > k) s.erase(s.find(dp[i - k - 1]));
            s.insert(dp[i] = *rbegin(s) + nums[i]);
        }
        return dp.back();
    }
};
