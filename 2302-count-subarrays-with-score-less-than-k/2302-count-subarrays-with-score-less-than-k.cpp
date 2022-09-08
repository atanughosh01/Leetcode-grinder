class Solution_1 {
public:
    long long countSubarrays(vector<int> &nums, long long k) {
        long long cnt = 0, sum = 0;
        int l = 0, r = 0;
        while (r < nums.size()) {
            sum += nums[r];
            while (sum * (r - l + 1) >= k) {
                sum -= nums[l++];
            }
            cnt += (r - l + 1);
            r++;
        }
        return cnt;
    }
};


class Solution {
public:
    long long countSubarrays(vector<int> &nums, long long k) {
        long long cnt = 0, sum = 0;
        int l = 0, r = 0;
        while (r < nums.size()) {
            sum += nums[r++];
            while (sum * (r - l) >= k) {
                sum -= nums[l++];
            }
            cnt += (r - l);
        }
        return cnt;
    }
};
