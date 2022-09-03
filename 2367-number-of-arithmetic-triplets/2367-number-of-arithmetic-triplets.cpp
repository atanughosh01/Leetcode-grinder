class Solution {
public:
    int arithmeticTriplets(vector<int> &nums, int diff) {
        int res = 0;
        unordered_map<int, bool> mp;
        for (int num : nums) mp[num] = true;
        for (int num : nums) {
            if (mp[num - diff] && mp[num + diff]) {
                res++;
            }
        }
        return res;
    }
};
