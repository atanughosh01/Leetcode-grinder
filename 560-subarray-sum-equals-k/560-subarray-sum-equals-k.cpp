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



class Solution {
public:
    int subarraySum(vector<int> &nums, int k) {
        int n = (int)(nums.size());
        int res = 0, pre[n];
        pre[0] = nums[0];
        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] + nums[i];
        }
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            if (pre[i] == k) res++;
            if (mp.find(pre[i] - k) != mp.end()) {
                res += mp[pre[i] - k];
            }
            mp[pre[i]]++;
        }
        return res;
    }
};
