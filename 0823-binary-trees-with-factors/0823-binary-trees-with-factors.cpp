class Solution {
public:
    int numFactoredBinaryTrees(vector<int> &arr) {
        long long count = 0;
        const int mod = 1e9+7;
        unordered_map<int, long long> mp;
        sort(arr.begin(), arr.end());
        for (auto a : arr){
            count = 1;
            for (auto b : arr){
                if (b > a) break;
                if (a % b==0) {
                    count = count % mod + (mp[b] * mp[a/b]) % mod;
                }
            }
            mp[a] = count % mod;
        }
        long long ans = 0;
        for (auto it : mp){
            ans += it.second;
            ans %= mod;
        }
        return ans;
    }
};
