class Solution_1 {
private:
    int atMost(vector<int> &arr, int k) {
        int cnt = 0, sum = 0, l = 0, r = 0;
        if (k < 0) return 0;
        while (r < arr.size()) {
            sum += arr[r];
            while (sum > k) {
                sum -= arr[l++];
            }
            cnt += (r - l + 1);
            r++;
        }
        return cnt;
    }
public:
    int numSubarraysWithSum(vector<int> &nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
};



class Solution {
public:
    int numSubarraysWithSum(vector<int> &nums, int goal) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int sum = 0, res = 0;
        for (int num : nums) {
            sum += num;
            res += mp[sum - goal];
            mp[sum]++;
        }
        return res;
    }
};
