class Solution {
private:
    vector<bool> vis;
    vector<vector<int>> res;
    void dfs(const vector<int> &nums, vector<int> &curr) {
        if (curr.size() == nums.size()) {
            res.push_back(curr);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (vis[i] || (i && !vis[i - 1] && nums[i] == nums[i - 1]))
                continue;
            vis[i] = true;
            curr.push_back(nums[i]);
            dfs(nums, curr);
            curr.pop_back();
            vis[i] = false;
        }
        return;
    }
public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vis.resize(nums.size(), false);
        vector<int> curr;
        dfs(nums, curr);
        return res;
    }
};
