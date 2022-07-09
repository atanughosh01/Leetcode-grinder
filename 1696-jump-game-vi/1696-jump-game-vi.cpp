// TLE
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



// TLE
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



// TLE
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



class Solution_4 {
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



class Solution {
public:
    int maxResult(vector<int> &nums, int k) {
        vector<int> dp(size(nums));
        dp[0] = nums[0];
        deque<int> q{0};
        for (int i = 1; i < nums.size(); i++) {
            if (q.front() < i - k) q.pop_front();
            dp[i] = nums[i] + dp[q.front()];
            while (!q.empty() && dp[q.back()] <= dp[i]) {
                q.pop_back();
            }
            q.push_back(i);
        }
        return dp.back();
    }
};
