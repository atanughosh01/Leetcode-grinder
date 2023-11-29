// Bruteforce | O(n^3) time | O(1) space
class Solution_1 {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        int res = nums[0] + nums[1] + nums[2];
        int n = nums.size();
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    int sum = (nums[i] + nums[j] + nums[k]);
                    if (abs(target - res) >  abs(target - sum)) {
                        res = sum;
                    }
                }
            }
        }
        return res;
    }
};



// Optimal | O(n^2) time | O(1) space | Two Pointers
class Solution_2 {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        int res = nums[0] + nums[1] + nums[2];
        int n = nums.size(), l = 0, r = n - 1;
        for (int i = 0; i < n; i++) {
            l = i + 1, r = n - 1;
            while (l < r) {
                int sum = (nums[i] + nums[l] + nums[r]);
                if (abs(target - res) >  abs(target - sum)) {
                    res = sum;
                }
                if (sum < target) l++;
                else if (sum > target) r--;
                else return target;
            }
        }
        return res;
    }
};



// Most Optimal | O(n^2) time | O(1) space | Two Pointers, Skip Duplicates
class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        int res = nums[0] + nums[1] + nums[2];
        int n = nums.size(), l = 0, r = n - 1;
        for (int i = 0; i < n; i++) {
            l = i + 1, r = n - 1;
            while (i < n - 1 && nums[i + 1] == nums[i]) i++; // skip duplicates
            while (l < r) {
                int sum = (nums[i] + nums[l] + nums[r]);
                if (abs(target - res) >  abs(target - sum)) {
                    res = sum;
                }
                if (sum < target) l++;
                else if (sum > target) r--;
                else return target;
            }
        }
        return res;
    }
};
