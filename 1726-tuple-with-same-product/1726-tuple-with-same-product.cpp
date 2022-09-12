class Solution {
public:
    int tupleSameProduct(vector<int> &nums) {
        int n = nums.size(), res = 0;
        unordered_map<int,int> mp;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                long long prod = nums[i] * 1ll * nums[j];
                res += 8 * mp[prod];
                mp[prod]++;
            }
        }
        return res;
    }
};
