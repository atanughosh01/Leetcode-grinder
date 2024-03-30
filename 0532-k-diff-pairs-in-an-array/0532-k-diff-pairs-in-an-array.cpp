class Solution_1 {
public:
    int findPairs(vector<int> &nums, int k) {
        int n = nums.size();
        set<pair<int, int>> s;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (abs(nums[i] - nums[j]) == k) {
                    int ff = min(nums[i], nums[j]);
                    int ss = max(nums[i], nums[j]);
                    s.insert({ff, ss});
                }
            }
        }
        return s.size();
    }
};


// I have no idea why my Binary Search Implementation isn't working, LOL
class Solution_2 {
private:
    int binSrch(vector<int> &arr, int l, int r, int x) {
        if (r >= l) {
            int mid = l + (r - l) / 2;
            if (arr[mid] == x) return mid;
            if (arr[mid] > x) return binSrch(arr, l, mid - 1, x);
            return binSrch(arr, mid + 1, r, x);
        }
        return -1;
    }
public:
    int findPairs(vector<int> &nums, int k) {
        int n = nums.size();
        set<pair<int, int>> s;
        for (int i = 0; i < n; ++i) {
            int tar = k + nums[i];
            int idx = binSrch(nums, 0, n - 1, tar);
            if (idx != -1 and idx != i) {
                s.insert({nums[i], tar});
            }
        }
        return s.size();
    }
};


// O(N)
class Solution {
public:
    int findPairs(vector<int> &nums, int k) {
        if (k < 0) return 0;
        unordered_map<int, int> mp;
        for (int n : nums) mp[n]++;
        int cnt = 0;
        for (auto p : mp) {
            if ((!k && p.second > 1) || (k && mp.count(p.first + k))) {
                cnt++;
            }
        }
        return cnt;
    }
};
