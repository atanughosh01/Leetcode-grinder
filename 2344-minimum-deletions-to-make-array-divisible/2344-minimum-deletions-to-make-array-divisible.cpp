class Solution {
public:
    int minOperations(vector<int> &nums, vector<int> &numsDivide) {
        sort(nums.begin(), nums.end());
        int g = numsDivide[0], n = nums.size();
        for (int &n : numsDivide) g = __gcd(g, n);
        for (int i = 0; i < n; i++) {
            if (nums[i] > g) break;
            if (g % nums[i] == 0) {
                return i;
            }
        }
        return -1;
    }
};
