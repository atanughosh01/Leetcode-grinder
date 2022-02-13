class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res = {{}};
        for(int num : nums) {  
            int n = (int)res.size();
            for(int i=0; i<n; ++i) {
                res.emplace_back(res[i]);
                res.back().emplace_back(num);
            }
        }
        return res;
    }
};
