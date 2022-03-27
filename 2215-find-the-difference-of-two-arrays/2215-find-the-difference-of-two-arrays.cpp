/*
    class Solution {
    public:
        vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
            vector<vector<int>> res;
            vector<int> ff, ss;
            unordered_set<int> st1, st2;
            for (int i=0; i<nums1.size(); i++) {
                for (int j=0; j<nums2.size(); j++) {
                    if (nums1[i] == nums2[j]) break;
                    else if(j == nums2.size()-1)
                        st1.insert(nums1[i]);
                }
            }
             for (int i=0; i<nums2.size(); i++) {
                for (int j=0; j<nums1.size(); j++) {
                    if (nums2[i] == nums1[j]) break;
                    else if(j == nums1.size()-1)
                        st2.insert(nums2[i]);
                }
            }
            for (auto &it1 : st1) ff.emplace_back(it1);
            for (auto &it2 : st2) ss.emplace_back(it2);
            res.emplace_back(ff);
            res.emplace_back(ss);
            return res;
        }
    };
*/



class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> res(2);
        unordered_set<int> st1, st2;
        for (auto x : nums1) st1.insert(x);
        for (auto y : nums2) st2.insert(y);
        for (auto it1 : st1) {
            if (st2.count(it1) == 0)
                res[0].emplace_back(it1);
        }
        for (auto it2 : st2) {
            if (st1.count(it2) == 0)
                res[1].emplace_back(it2);
        }
        return res;
    }
};
