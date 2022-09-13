class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res = {{}};
        int sz = 0, startIdx = 0;
        for (int i = 0; i < nums.size(); i++) {
            startIdx = (i >= 1 && nums[i] == nums[i - 1]) ? sz : 0;
            sz = res.size();
            for (int j = startIdx; j < sz; j++) {
                vector<int> sub = res[j];
                sub.push_back(nums[i]);
                res.push_back(sub);
            }
        }
        return res;      
    }
};
