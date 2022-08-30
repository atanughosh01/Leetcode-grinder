class Solution_1 {
public:
    vector<int> buildArray(vector<int> &nums) {
        vector<int> res;
        for (int num : nums) {
            res.push_back(nums[num]);
        }
        return res;
    }
};


class Solution {
public:
    vector<int> buildArray(vector<int> &nums) {
        int n = nums.size();
        for (int &num : nums) {
			num += n * (nums[num] % n);
		}
		for (int &num : nums) {
			num /= n;
		}
		return nums;
    }
};
