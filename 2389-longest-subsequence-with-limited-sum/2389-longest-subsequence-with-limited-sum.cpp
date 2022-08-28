class Solution {
   public:
    vector<int> answerQueries(vector<int> &nums, vector<int> &queries) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            nums[i] += nums[i - 1];
        }
        vector<int> ans;
        for (int query : queries) {
            int j = 0;
            for (; j < nums.size(); j++) {
                if (nums[j] > query) break;
            }
            ans.emplace_back(j);
        }
        return ans;
    }
};
