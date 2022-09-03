// O(n^3) time, O(1) space
class Solution_1 {
public:
    int arithmeticTriplets(vector<int> &nums, int diff) {
        int n = nums.size(), res = 0;
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (nums[k] - nums[j] == diff && nums[j] - nums[i] == diff) {
                        res++;
                    }
                }
            }
        }
        return res;
    }
};


// O(n) time, O(n) space
class Solution_2 {
public:
    int arithmeticTriplets(vector<int> &nums, int diff) {
        int res = 0;
        unordered_map<int, bool> mp;
        for (int num : nums) mp[num] = true;
        for (int num : nums) {
            if (mp[num - diff] && mp[num + diff]) {
                res++;
            }
        }
        return res;
    }
};


// O(n) time, O(1) space
class Solution {
public:
    int arithmeticTriplets(vector<int> &nums, int diff) {
        int res = 0;
        int freq[201]{0};
        for (int num : nums) freq[num] = 1;
        for (int num : nums) {
            if (num >= 2*diff && freq[num - diff] && freq[num - 2*diff]) {
                res++;
            }
        }
        return res;
    }
};
