class Solution {
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        vector<int> res;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        for (int &x : nums2) {
            if (binary_search(nums1.begin(), nums1.end(), x) && (res.empty() || res.back() != x)) {
                res.push_back(x);
            }
        }
        return res;
    }
};
