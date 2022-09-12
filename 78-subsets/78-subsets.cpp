class Solution {
public:
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> res = {{}};
        for (int &num : nums) {  
            int n = res.size();
            for (int i = 0; i < n; i++) {
                vector<int> temp = res[i];
                temp.push_back(num);
                res.push_back(temp);
            }
        }
        return res;
    }
};
