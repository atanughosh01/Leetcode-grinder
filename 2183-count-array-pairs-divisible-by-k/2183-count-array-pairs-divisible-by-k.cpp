/*
    // B R U T E
    class Solution {
    public:
        long long countPairs(vector<int>& nums, int k) {
            int n = (int)nums.size();
            long long cnt = 0;
            for(int i=0; i<n; ++i) {
                for(int j=i+1; j<n; ++j) {
                    if((nums[i]*1ll*nums[j]) % k == 0)
                        cnt++;
                }
            }
            return cnt;
        }
    };
*/


/*
    // O P T I M I S E D
    class Solution {
    public:
        long long countPairs(vector<int>& nums, int k) {
            long long res = 0;
            unordered_map<long long, long long> gcds;
            for (int n : nums) {
                long long gcd_i = gcd(n, k);
                for (auto [gcd_j, cnt] : gcds) {
                    if((gcd_i * gcd_j)%k == 0)
                        res += cnt;
                }
                gcds[gcd_i]++;
            }
            return res;
        }
    };
*/


// M O S T   O P T I M I S E D
class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        long long res = 0;
        vector<pair<int, int>> factors;
        for (int i = 1; i * i <= k; ++i)
            if (k % i == 0) {
                factors.push_back({i, 0});
                if (k / i != i)
                    factors.push_back({k / i, 0});
            }
        for (int n : nums) {
            long long gcd_nk = gcd(n, k);
            for (auto &[factor, cnt] : factors) {
                if((gcd_nk * factor) % k == 0)
                    res += cnt;
                if (gcd_nk == factor)
                    ++cnt;
            }
        }
        return res;
    }
};
