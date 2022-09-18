// Bruteforce | O(n * m) Time | O(max(n, m)) Space
class Solution_1 {
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        vector<int> res;
        for (int &x : nums1) {
            for (auto it = nums2.begin(); it != nums2.end(); it++) {
                if (x == *it) {
                    res.push_back(x);
                    nums2.erase(it);
                    break;
                }
            }
        }
        return res;
    }
};


// Optimal | O(n) + O(m) Time | O(n) + O(m) Extra Space
class Solution_2 {
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        vector<int> res;
        unordered_map<int, int> freq;
        for (int &x : nums1) freq[x]++;
        for (int &y : nums2) {
            if (freq[y] > 0) {
                res.push_back(y);
                freq[y]--;
            }
        }
        return res;
    }
};



// Same approach but runtime is a bit faster
class Solution_3 {
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        vector<int> res;
        int freq[1001]{0};
        for (int &x : nums1) freq[x]++;
        for (int &y : nums2) {
            if (freq[y] > 0) {
                res.push_back(y);
                freq[y]--;
            }
        }
        return res;
    }
};



// 2 Pointer Approach | Not Most Optimal | O(NlogN) + O(MlogM) time | O(max(N, M)) Space
class Solution {
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        vector<int> res;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int l = 0, r = 0;
        // This below part is of Linear Time Complexity
        // If the arrays are already sorted, we can do it linearly
        while (l < nums1.size() && r < nums2.size()) {
            if (nums1[l] == nums2[r]) {
                res.push_back(nums1[l]);
                l++, r++;
            } else if (nums1[l] > nums2[r]) {
                r++;
            } else {
                l++;
            }
        }
        return res;
    }
};
