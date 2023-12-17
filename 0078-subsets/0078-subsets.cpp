class Solution_1 {
public:
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> subs = {{}};
        for (int &num : nums) {  
            int sz = subs.size();
            for (int i = 0; i < sz; i++) {
                vector<int> sub = subs[i];
                sub.push_back(num);
                subs.push_back(sub);
            }
        }
        return subs;
    }
};


class Solution {
public:
    vector<vector<int>> subsets(vector<int> &nums) {
        int n = nums.size(), sz = 1 << n;
        vector<vector<int>> subs(sz);
        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < n; j++) {
                if ((i >> j) & 1) {
                    subs[i].push_back(nums[j]);
                }
            }
        }
        return subs;
    }
};
