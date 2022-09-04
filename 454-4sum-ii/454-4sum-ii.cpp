// Bruteforce | O(n^4) time | O(1) space
class Solution_1 {
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4) {
        int cnt = 0;
        for (int i : nums1) {
            for (int j : nums2) {
                for (int k : nums3) {
                    for (int l : nums4) {
                        if (i + j + k + l == 0) {
                            cnt++;
                        }
                    }
                }
            }
        }
        return cnt;
    }
};


// Better | O(n^3) time | O(n) space
class Solution_2 {
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4) {
        unordered_map<int, int> mp;
        for (int l : nums4) mp[l]++;
        int cnt = 0;
        for (int i : nums1) {
            for (int j : nums2) {
                for (int k : nums3) {
                    cnt += mp[-(i + j + k)];
                }
            }
        }
        return cnt;
    }
};


// Optimal | O(n^2) time | O(n^2) space
class Solution {
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4) {
        unordered_map<int, int> mp;
        for (int k : nums3) {
            for (int l : nums4) {
                mp[k + l]++;
            }
        }
        int cnt = 0;
        for (int i : nums1) {
            for (int j : nums2) {
                cnt += mp[-(i + j)];
            }
        }
        return cnt;
    }
};
