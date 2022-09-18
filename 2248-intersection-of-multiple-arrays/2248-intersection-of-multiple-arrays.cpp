class Solution {
public:
    vector<int> intersection(vector<vector<int>> &nums) {
        int cnt[1001]{0};
        vector<int> res;
        for (auto &arr: nums) {
            for (int &n : arr) {
                cnt[n]++;
            }
        }
        for (int i = 0; i < 1001; i++) {
            if (cnt[i] == nums.size()) {
                res.push_back(i);
            }
        }
        return res;

    }
};
