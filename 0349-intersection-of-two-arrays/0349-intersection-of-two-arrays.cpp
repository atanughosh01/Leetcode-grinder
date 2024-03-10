// O(N * log(N)) time
class Solution_1 {
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



// O(N) time in average case
class Solution {
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        unordered_set<int> st(nums1.begin(), nums1.end());
        vector<int> res;
        for (int &x : nums2) {
            if (st.find(x) != st.end()) {
                res.push_back(x);
                st.erase(x);
            }
        }
        return res;
    }
};
