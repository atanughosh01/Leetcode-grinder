class Solution {
private:
    void dfs(vector<int>& candidates, int target, int index, vector<int>& path, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(path);
            return;
        }
        for (int i = index; i < candidates.size(); i++) {
            if (target < candidates[i]) {
                break;
            }
            if (i > index && candidates[i] == candidates[i - 1]) {
                continue;
            }
            path.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i + 1, path, res);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, path, res);
        return res;
    }
};
