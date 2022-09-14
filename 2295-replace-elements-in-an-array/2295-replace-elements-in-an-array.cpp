class Solution {
public:
    vector<int> arrayChange(vector<int> &nums, vector<vector<int>> &oprs) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]] = i;
        }
        for (vector<int> &opr : oprs) {
            nums[mp[opr[0]]] = opr[1];
            mp[opr[1]] = mp[opr[0]];
        }
        return nums;
    }
};
