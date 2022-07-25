class Solution_1 {
public:
    vector<int> targetIndices(vector<int> &nums, int target) {
        vector<int> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                res.push_back(i);
            }
        }
        return res;
    }
};



class Solution {
public:
    vector<int> targetIndices(vector<int> &nums, int target) {
        vector<int> res;
        int count = 0, rank = 0;
        for (int &num : nums) {
            count += (num == target);
            rank += (num < target);
        }
        while (count--) {
            res.push_back(rank++);
        }
        return res;
    }
};
