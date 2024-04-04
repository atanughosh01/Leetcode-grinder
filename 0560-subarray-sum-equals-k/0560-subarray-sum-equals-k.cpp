// O(N^2) time, O(1) space
class Solution_1 {
public:
    int subarraySum(vector<int> &nums, int k) {
        int n = (int)(nums.size());
        int sum = 0, count = 0;
        for (int i = 0; i < n; i++) {
            sum = nums[i];
            if (sum == k) count++;
            for (int j = i + 1; j < n; j++) {
                sum += nums[j];
                if (sum == k) count++;
            }
        }
        return count;
    }
};


// O(N) time, O(N) space
class Solution_2 {
public:
    int subarraySum(vector<int> &nums, int k) {
        int n = (int)(nums.size());
        int res = 0, pre[n];
        pre[0] = nums[0];
        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] + nums[i];
        }
        unordered_map<int, int> mp;
        mp[0]++;
        for (int i = 0; i < n; i++) {
            res += mp[pre[i] - k];
            mp[pre[i]]++;
        }
        return res;
    }
};


// O(N) time, O(N) space, but better
class Solution {
public:
    int subarraySum(vector<int> &nums, int k) {
        int sum = 0, res = 0;
        unordered_map<int,int> mp;
        mp[0]++;
        for (int &num : nums) {
            sum += num;
            res += mp[sum - k];
            mp[sum]++;
        }
        return res;
    }
};


// This solution (actually not a solution) would be the best if all the numbers were non-negetive
// O(N) time, O(1) space, sliding window
class Solution_3 {
public:
    int subarraySum(vector<int> &nums, int k) {
        int n = (int)(nums.size());
        int l = 0, r = 0, sum = 0, res = 0;
        while (r < n && l < n) {
            sum += nums[r];
            if (sum == k) {
                res++;
                r++;
            } else if (sum < k) {
                r++;
            } else if (sum > k) {
                sum -= nums[l];
                l++;
                sum -= nums[r];
            }
        }
        return res;
    }
};
