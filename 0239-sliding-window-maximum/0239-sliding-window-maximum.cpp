// Bruteforce | O((n-k) * k) Time | O(n) Space
class Solution_1 {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        vector<int> res;
        int n = nums.size(), mx = INT_MIN;
        for (int i = 0; i < n - k + 1; i++) {
            mx = nums[i];
            for (int j = i + 1; j < i + k; j++) {
                mx = max(mx, nums[j]);
            }
            res.push_back(mx);
        }
        return res;
    }
};



// Optimal | O(n) Time | O(n) + O(k) Space
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        vector<int> res;
        deque<int> dq;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (!dq.empty() && dq.front() == i - k) dq.pop_front();
            while (!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
            dq.push_back(i);
            if (i >= k - 1) res.push_back(nums[dq.front()]);
        }
        return res;
    }
};
