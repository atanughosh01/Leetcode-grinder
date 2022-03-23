class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> res, pos, neg;
        for (int x : nums) {
            if (x > 0) pos.emplace_back(x);
            else neg.emplace_back(x);
        }
        int n = (int)pos.size();
        for (int i=0; i<n; i++) {
            res.emplace_back(pos[i]);
            res.emplace_back(neg[i]);
        }
        return res;
    }
};
