class Solution {
public:
    bool isGoodArray(vector<int> &nums) {
        int gcd = nums[0];
        for (int &n : nums) gcd = __gcd(gcd, n);
        return gcd == 1;
    }
};
