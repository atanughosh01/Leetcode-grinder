class Solution_1 {
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



class Solution {
public:
    vector<int> findErrorNums(vector<int> &nums) {
        int n = nums.size();
        vector<int> res(2, -1);
        for (int i = 0; i < n; i++) {
            while (nums[i] != i + 1){
                if (nums[i] == nums[nums[i] - 1]) {
                    res[0] = nums[i];
                    res[1] = i + 1;
                    break;
                } else {
                    swap(nums[i], nums[nums[i] - 1]);
                }
            }
        }
        return res;
    }
};
