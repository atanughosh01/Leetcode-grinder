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
        for (int i = 0; i < n; i++) {
			nums[i] = nums[i] + n * (nums[nums[i]] % n);
		}
		for (int i = 0; i < n; i++) {
			nums[i] = nums[i] / n;
		}
		return nums;
    }
};
