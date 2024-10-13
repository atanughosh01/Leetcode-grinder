class Solution {
public:
    vector<int> smallestRange(vector<vector<int>> &nums) {
        vector<int> res;
        vector<pair<int, int>> pairs;
        unordered_map<int, int> count;
        int i = 0, k = 0, n = nums.size();
        for (int x = 0; x < n; x++) {
            for (int &n : nums[x]) {
                pairs.push_back({n, x});
            }
        }
        int m = pairs.size();
        sort(pairs.begin(), pairs.end());
        for (int j = 0; j < m; j++) {
            if (!count[pairs[j].second]++) k++;
            if (k == n) {
                while (count[pairs[i].second] > 1) count[pairs[i++].second]--;
                if (res.empty() || res[1] - res[0] > pairs[j].first - pairs[i].first) {
                    res = {pairs[i].first, pairs[j].first};
                }
            }
        }
        return res;
    }
};
