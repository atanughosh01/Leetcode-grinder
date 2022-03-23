/*
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
*/


class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> ans(n, 0);
        int pos_idx = 0, neg_idx=1;
        for (auto num: nums){
            if(num>0){
                ans[pos_idx] = num;
                pos_idx += 2;
            } else {
                ans[neg_idx] = num;
                neg_idx += 2;
            }
        }
        return ans;
    }
};
