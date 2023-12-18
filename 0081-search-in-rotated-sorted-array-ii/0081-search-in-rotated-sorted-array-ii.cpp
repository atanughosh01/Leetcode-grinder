class Solution {
public:
	bool search(vector<int> &nums, int target) {
		sort(nums.begin(), nums.end());
		int l = 0, r = nums.size() - 1;
		while (l <= r) {
			int mid = l + (r - l) / 2;
			if (target == nums[mid]) return true;
			if (target < nums[mid]) r = mid - 1;
			if (target > nums[mid]) l = mid + 1;
		}
		return false;
	}
};
