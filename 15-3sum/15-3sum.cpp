// Bruteforce, O(n^3) time, O(n) extra space, n = nums.length
class Solution_1 {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        int n = nums.size();
        set<vector<int>> st;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        st.insert({nums[i], nums[j], nums[k]});
                    }
                }
            }
        }
        vector<vector<int>> res(st.begin(), st.end());
        return res;
    }
};



// Optimized, O(n^2) time, O(n) extra space, n = nums.length
class Solution_2 {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        int n = nums.size();
        set<vector<int>> st;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++) {
            int l = i + 1, r = n - 1, target = -nums[i];
            while (l < r) {
                if (nums[l] + nums[r] == target) {
                    st.insert({nums[i], nums[l], nums[r]});
                    l++, r--;
                }
                else if (nums[l] + nums[r] < target) l++;
                else r--;
            }
        }
        vector<vector<int>> res(st.begin(), st.end());
        return res;
    }
};



// Optimized, O(n^2) time, O(1) extra space, n = nums.length
class Solution_3 {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++) {
            int l = i + 1, r = n - 1, target = -nums[i];
            while (i < n - 1 && nums[i + 1] == nums[i]) i++;
            while (l < r) {
                if (nums[l] + nums[r] == target) {
                    res.push_back({nums[i], nums[l], nums[r]});
                    while (l < r && nums[l] == nums[l + 1]) l++;
                    while (l < r && nums[r] == nums[r - 1]) r--;
                    l++, r--;
                }
                else if (nums[l] + nums[r] < target) l++;
                else r--;
            }
        }
        return res;
    }
};



// Optimized, O(n^2) time, O(1) extra space, n = nums.length || Better
class Solution_4 {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++) {
            int l = i + 1, r = n - 1, target = -nums[i];
            while (i < n - 1 && nums[i + 1] == nums[i]) i++;
            while (l < r) {
                if (nums[l] + nums[r] == target) {
                    vector<int> triplet = {nums[i], nums[l], nums[r]};
                    res.push_back(triplet);
                    while (l < r && nums[l] == triplet[1]) l++;
                    while (l < r && nums[r] == triplet[2]) r--;
                }
                else if (nums[l] + nums[r] < target) l++;
                else r--;
            }
        }
        return res;
    }
};



// Optimized, O(n^2) time, O(1) extra space, n = nums.length || Best
class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++) {
            int l = i + 1, r = n - 1, target = -nums[i];
            if (target < 0) break;
            while (i < n - 1 && nums[i + 1] == nums[i]) i++;
            while (l < r) {
                if (nums[l] + nums[r] == target) {
                    vector<int> triplet = {nums[i], nums[l], nums[r]};
                    res.push_back(triplet);
                    while (l < r && nums[l] == triplet[1]) l++;
                    while (l < r && nums[r] == triplet[2]) r--;
                }
                else if (nums[l] + nums[r] < target) l++;
                else r--;
            }
        }
        return res;
    }
};
