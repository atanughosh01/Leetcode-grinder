// B R U T E
class Solution_1 {
public:
    long long countPairs(vector<int> &nums, int k) {
        int n = nums.size();
        long long cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if ((nums[i] * 1ll * nums[j]) % k == 0) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};



// O P T I M I S E D
class Solution {
public:
    long long countPairs(vector<int> &nums, int k) {
        long long res = 0;
        unordered_map<long long, long long> gcds;
        for (int &num : nums) {
            long long gcd_i = __gcd(num, k);
            for (auto &[gcd_j, cnt] : gcds) {
                if ((gcd_i * 1ll * gcd_j) % k == 0) {
                    res += cnt;
                }
            }
            gcds[gcd_i]++;
        }
        return res;
    }
};