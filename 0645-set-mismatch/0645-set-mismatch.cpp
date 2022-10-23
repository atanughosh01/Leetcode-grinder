class Solution {
public:
    vector<int> findErrorNums(vector<int> &nums) {
        int n = nums.size(), absent, repeat;
        unordered_map<int, int> mp;
        for (int &num : nums) mp[num]++;
        for (int i = 1; i <= n; i++) {
            if (mp[i] == 0) absent = i;
            if (mp[i] == 2) repeat = i;
        }
        return {repeat, absent};
    }
};
