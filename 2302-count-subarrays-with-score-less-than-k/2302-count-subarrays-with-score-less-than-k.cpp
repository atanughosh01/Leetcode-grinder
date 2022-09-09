// O(N) time | O(1) space | N = nums.length | Most Optimal
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



// O(Nlog(N)) time | O(N) space | N = nums.length | Optimal
class Solution {
public:
    long long countSubarrays(vector<int> &nums, long long k) {
        int n = nums.size();
        vector<long long> pre(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            pre[i] += pre[i - 1] + nums[i - 1];
        }
        long long res = 0, sum = 0;
        for (int i = 1; i <= n; i++) {
            int l = i, r = n, temp = -1;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                sum = pre[mid] - pre[i - 1];
                sum *= (mid - i + 1);
                if (sum >= k) {
                    r = mid - 1;
                } else {
                    temp = mid;
                    l = mid + 1;
                }
            }
            if (temp != -1) {
                res += (temp - i + 1);
            }
        }
        return res;
    }
};
